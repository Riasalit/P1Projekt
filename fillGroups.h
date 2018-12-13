int calcBenefit(const student test_person, const group test_group){
  int counter = 0;
  int i, j;
  int checkedRole = 0;
  for(i = 0; i < ROLES_IN_STUDENT; i++){
    for(j = 0; j < ROLES_IN_GROUP; j++){
      if(test_person.role[i] == test_group.roles[j]) checkedRole = 1;
      if(!checkedRole) counter++;
    }
  }
  return counter;
}

void addRolesToGroup(group *group){
  int i, j, k, checkedRole = 0, h = 0, hasRole = 0;
  for(i = 0; i < group->studentsInGroup; i++){
    for(j = 0 ; j < ROLES_IN_STUDENT; j++){
      for(k = 0; k < ROLES_IN_GROUP; k++){
        if(group->students[i].isStudent && (group->students[i].role[j] != group->roles[k]) && !checkedRole && (group->students[i].role[j] != nothing)){
          checkedRole++;
          hasRole = 0;
          while(h < ROLES_IN_GROUP && group->roles[h] != nothing){
            if (group->roles[h] == group->students[i].role[j]) {
              hasRole = 1;
            }
            h++;
          }
          if (!hasRole) {
          group->roles[h] = group->students[i].role[j];
          group->amountOfRoles +=1;
          }

          h = 0;
        }
      }
      checkedRole = 0;
    }
  }
}

void fillGroups(student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  int i, j, index = 0, tempBestValue;
  int currentBenefit;
  for(i = 0; i < nrOfStudents; i++){
    tempBestValue = 0;
    for(j = 0; j < nrOfGroups; j++){
      currentBenefit = calcBenefit(class[i], groups[j]);
      if(index < currentBenefit && (groups[j].studentsInGroup < groupSize)){
        index = currentBenefit;
        tempBestValue = j;
      } else if ((index == currentBenefit || currentBenefit == 0) && (groups[j].studentsInGroup < groupSize) && (groups[j].studentsInGroup < groups[tempBestValue].studentsInGroup)){
        tempBestValue = j;
      }
    }
    groups[tempBestValue].students[groups[tempBestValue].studentsInGroup] = class[i];
    groups[tempBestValue].studentsInGroup++;
    addRolesToGroup(&groups[tempBestValue]);
    index = 0;
  }
  free(class), class = NULL;
}
