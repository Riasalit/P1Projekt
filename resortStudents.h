/*
##############################
allocate space for an int array
##############################*/
int *allocateIntArray(const int length){
  int *array;
  array = calloc(length, sizeof(int));
  if(array == NULL){
    printf("could not allocate space for an int array\n");
    exit(EXIT_FAILURE);
  }
  return array;
}

/*
###############################################################################
compare the student at groupIndex with the rest of the students in that array
if a unique role is found within that student, add one to the uniqueRoles array
###############################################################################*/
void compareToRestOfGroup(const group *groups, const int groupIndex, const int studentIndex, const int roleIndex, int *uniqueRoles){
  int unique = 1, sameRoles;
  int i, j;
  /* only run if the role isnt nothing */
  if(groups[groupIndex].students[studentIndex].role[roleIndex] != nothing){
    for(i = 0; i < groups[groupIndex].studentsInGroup; i++){ /* iterate through groups */
      for(j = 0; j < ROLES_IN_STUDENT; j++){ /* iterate through roles */
          if(i != studentIndex){ /* compare input studnet with the rest in the group */
            sameRoles = (groups[groupIndex].students[studentIndex].role[roleIndex] ==
                        groups[groupIndex].students[i].role[j]);
            if(sameRoles) unique = 0; /* count if multiple of same role was found */
          }
        }
      }
    }else{
      unique = 0;
    }

    /* if there is no dublicates, add one to the array of uniqueRoles */
    if (unique == 1){
      uniqueRoles[studentIndex] += 1;
    }
  }

/*
#################################################################
remake the array that keeps track of what roles are in the groups
#################################################################*/
void fixGroupRoleArray(const int nrOfGroups, const int groupSize, group *groups){
  int i, j, k, l;
  int unique = 0;
  int index = 0;

  for(i = 0; i < nrOfGroups; i++){ /* iterate throug all groups */
    groups[i].amountOfRoles = 0;
    for(j = 0; j < ROLES_IN_GROUP; j++){ /* iterate through all roles */
      groups[i].roles[j] = nothing; /* sets all roles in group "i" to nothing */
    }
    index = 0;
    for(j = 0; j < groups[i].studentsInGroup; j++){ /* iterate throug all inices of students in group "i" */
      for(k = 0; k < ROLES_IN_STUDENT; k++){ /* iterate through all roles in student "j" in group "i" */
        unique = 1; /* reset "unique" boolean value  */
        for(l = 0; l < ROLES_IN_GROUP; l++){ /* iterate through all roles in group "i" */
          /* check if the role in student "j" already is in group "i"'s array of roles */
          if(groups[i].students[j].role[k] == groups[i].roles[l] || groups[i].students[j].role[k] == nothing) unique = 0;
        }
        /* if a role wasnt already in the groups array of roles, add it */
        if (unique) {
          groups[i].roles[index++] = groups[i].students[j].role[k];
          groups[i].amountOfRoles += 1;
        }
      }
    }
  }
}

/*
###################################################
remove people who doesnt contribute from the groups
###################################################*/
void resortStudents(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
/* take people out i who doesnt contribute for more than 1
   and insert them into other groups where they do more */
  int i, j, k;
  int x, y;
  int *uniqueRoles, *indices;
  int studentMax, countStudentsResort = 0;
  student *studentsResort;

  studentMax = nrOfGroups*groupSize; /* max amount of students needed to hit all indices in all groups */

  uniqueRoles = allocateIntArray(groupSize);
  indices = allocateIntArray(studentMax);
  for(i = 0; i < studentMax; i++){
    indices[i] = 0; /* initiate all indices in the indices array */
  }

  for(i = 0; i < nrOfGroups; i++){
    for(j = 0; j < groupSize; j++){
      uniqueRoles[j] = 0; /* reset the unique roles array */
    }
    for(j = 0; j < groups[i].studentsInGroup; j++){
      if(groups[i].students[j].isStudent){
        /* compare a student to the rest of the group and add one to the
           unique roles array for each unique role the student have */
        for(k = 0; k < ROLES_IN_STUDENT; k++){
          compareToRestOfGroup(groups, i, j, k, uniqueRoles);
        }
      }
    }
    for(j = 0; j < groups[i].studentsInGroup; j++){
      if(uniqueRoles[j] <= 2){
        countStudentsResort += 1; /* count the amount of students who needs to be resortet */
        /* find the index of each student who needs to be resortet in the 2d
        array "group[]student[]" and add it to the 1 d array.
        formula = (1st index * size of 2nd array + index of 2nd array) */
        indices[i*groupSize+j] = 1;
      }
    }
  }
  free(uniqueRoles), uniqueRoles = NULL;

  /* allocate the space for students to resort */
  studentsResort = calloc(countStudentsResort , sizeof(student));
  if (studentsResort == NULL){
    perror("ERROR: studentsResort ");
    exit(EXIT_FAILURE);
  }
  j=0;
  for(i = 0; i < studentMax; i++){
    if (indices[i]){
      /* the revers of (1st index * size of 2nd array + index of 2nd array)
      to remove them from the original array and add the students to studentsResort */
      x = i/groupSize;
      y = i%groupSize;
      studentsResort[j++] = groups[x].students[y];
      groups[x].students[y].isStudent = 0;
      groups[x].studentsInGroup -= 1;
    }
  }

  sortGroups(nrOfGroups, groupSize, groups); /* move the non-students to the last indices of the groups */
  fixGroupRoleArray(nrOfGroups, groupSize, groups);
  free(indices), indices = NULL;
  randomizeStudents(countStudentsResort, studentsResort);
  fillGroups(studentsResort, groupSize, countStudentsResort, nrOfGroups, groups);
}
