/*
##############################
Calculate how many unique roles a student contributes to a group
##############################*/
int calcBenefit(const student test_person, const group test_group){
  int counter = 0;
  int i, j;
  int checkedRole = 0;
  for(i = 0; i < ROLES_IN_STUDENT; i++){/*iterate through each role the student has*/
    for(j = 0; j < ROLES_IN_GROUP; j++){/*iterate through each role the group has*/
      if(test_person.role[i] == test_group.roles[j]) checkedRole = 1;/*if a student has a role that is not in the group, counter goes up*/
      if(!checkedRole) counter++;
    }
  }
  return counter;
}

/*
##############################
Finds every role represented by the students in the group and add them to the group's array containing the roles.
##############################*/
void addRolesToGroup(group *group){
  int i, j, k, h = 0, hasRole = 0;/*hasRole is used as a boolean*/
  for(i = 0; i < group->studentsInGroup; i++){/*iterate through every student in the group*/
    for(j = 0 ; j < ROLES_IN_STUDENT; j++){/*iterate through every role in the student in the group*/
      for(k = 0; k < ROLES_IN_GROUP; k++){/*iterate through every role in the group*/
        if(group->students[i].isStudent && (group->students[i].role[j] != group->roles[k]) && (group->students[i].role[j] != nothing)){/*if the space in the group is actually a student and not an empty space, and the students role being checked is not equal to the groups role, and the role is not equal to nothing*/
          hasRole = 0;
          while(h < ROLES_IN_GROUP && group->roles[h] != nothing){/*iterate through the roles in the group until nothing is found*/
            if (group->roles[h] == group->students[i].role[j]) {/*if the students role exists in the group hasRole is set to 1*/
              hasRole = 1;
            }
            h++;
          }
          if (!hasRole) {/*if the group doesnt have the students role, add it to the array of roles, and increment amountOfRoles in group*/
            group->roles[h] = group->students[i].role[j];
            group->amountOfRoles +=1;
          }
          h = 0;
        }
      }
    }
  }
}

/*
##############################
Puts an array of students in to groups based on where they add the most amount of unique roles
##############################*/
void fillGroups(student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  int i, j, index = 0, tempBestValue, currentBenefit;
  for(i = 0; i < nrOfStudents; i++){/*iterate through the students*/
    tempBestValue = 0;/*make sure the index of the best group starts at 0*/
    for(j = 0; j < nrOfGroups; j++){/*iterate through every group*/
      currentBenefit = calcBenefit(class[i], groups[j]);/*Gets benefit added by student for current group*/
      if(index < currentBenefit && (groups[j].studentsInGroup < groupSize)){/*if the previous best group had less benefit from the current student than the current group, and the current group isn't too big*/
      index = currentBenefit;/*index stores highest benefit a group has gotten from student*/
      tempBestValue = j;/*save the current group as the new best group for the student*/
      } else if ((index == currentBenefit) && (groups[j].studentsInGroup < groupSize) && (groups[j].studentsInGroup < groups[tempBestValue].studentsInGroup)){
        /*if the current benefit is the same as the best benefit and the group isnt at the maximum groupsize
        and the current group's amount of students is lower than the best group's amount of students */
        tempBestValue = j;
        index = currentBenefit;
      }
    }
    groups[tempBestValue].students[groups[tempBestValue].studentsInGroup] = class[i];/*puts the student into the group where he added the most roles*/
    groups[tempBestValue].studentsInGroup++;/*increments the counter for how many students are in the group*/
    addRolesToGroup(&groups[tempBestValue]);/*adds the students unique roles, if any, to the group's array of roles*/
    index = 0;
  }
  free(class), class = NULL;/*frees the class array, to take less memory during runtime*/
}
