int *allocateIntArray(const int length){
  int *array;
  array = calloc(length, sizeof(int));
  if(array == NULL){
    printf("could not allocate space for an int array\n");
    exit(EXIT_FAILURE);
  }
  return array;
}

void compareToRestOfGroup(const group *groups, const int groupSize, const int groupIndex, const int studentIndex, const int roleIndex, int *uniqueRoles){
  int count = 0, sameRoles;
  int i, j;
  if(studentIndex + 1 != groupSize){
    for(i = studentIndex + 1; i < groupSize; i++){
      for(j = 0; j < ROLES_IN_STUDENT; j++){
        sameRoles = groups[groupIndex].students[studentIndex].role[roleIndex] ==
                    groups[groupIndex].students[i].role[j];
        if(sameRoles) count++;
      }
    }
  } else {
    for(i = studentIndex - 1; i >= 0; i--){
      for(j = 0; j < ROLES_IN_STUDENT; j++){
        sameRoles = groups[groupIndex].students[studentIndex].role[roleIndex] ==
                    groups[groupIndex].students[i].role[j];
        if(sameRoles) count++;
      }
    }
  }
  if (count == 0){
    uniqueRoles[studentIndex] += 1;
  }
}

void fixGroupRoleArray(const int nrOfGroups, const int groupSize, group *groups){
  int i, j, k, l;
  int unique = 0;
  int index = 0;

  for(i = 0; i < nrOfGroups; i++){
    for(j = 0; j < ROLES_IN_GROUP; j++){
      groups[i].roles[j] = nothing;
    }
    for(j = 0; j < groupSize; j++){
      for(k = 0; k < ROLES_IN_STUDENT; k++){
        unique = 1;
        for(l =0; l < ROLES_IN_GROUP; l++){
          if(groups[i].students[j].role[k] == groups[i].roles[l]) unique = 0;
        }
        if (unique) groups[i].roles[index++] = groups[i].students[j].role[k];
      }
    }
  }
}

void resortNormies(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
/*"take people out i who doesnt contribute for more than 1
and insert them into other groups where they do more" */
  int i, j, k, x, y;
  int *uniqueRoles, *indices;
  int studentMax, countStudentsResort = 0;
  student *studentsResort;

  studentMax = nrOfGroups*groupSize;

  uniqueRoles = allocateIntArray(groupSize);
  indices = allocateIntArray(studentMax);
  for(i = 0; i < studentMax; i++){
    indices[i] = 0;
  }

  for(i = 0; i < nrOfGroups; i++){
    for(j = 0; j < groupSize; j++){
      uniqueRoles[j] = 0;
    }
    for(j = 0; j < groups[i].studentsInGroup; j++){
      if(groups[i].students[j].isStudent){
        for(k = 0; k < ROLES_IN_STUDENT; k++){
          compareToRestOfGroup(groups, groups[i].studentsInGroup, i, j, k, uniqueRoles);
        }
      }
    }
    for(j = 0; j < groupSize; j++){
      if(uniqueRoles[j] == 0){
        countStudentsResort ++;
        indices[i*groupSize+j] = 1;
      }
    }
  }

  studentsResort = calloc(countStudentsResort , sizeof(student));
  if (studentsResort == NULL){
    printf("could not allocate the space needed for resorting students");
    exit(EXIT_FAILURE);
  }
  j=0;
  for(i = 0; i < studentMax; i++){
    if (indices[i]){
      x = i/groupSize;
      y = i%groupSize;
      studentsResort[j++] = groups[x].students[y];
      groups[x].students[y].isStudent = 0;
      groups[x].studentsInGroup -= 1;
    }
  }

  fixGroupRoleArray(nrOfGroups, groupSize, groups);
  sortGroups(nrOfGroups, groupSize, groups);
}
