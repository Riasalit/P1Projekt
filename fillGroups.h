int calcBenefit(const student test_person, const group test_group){
  int counter = ROLES_IN_STUDENT;
  int i, j;
  int checkedRole = 0;
  for(i = 0; i < ROLES_IN_STUDENT; i++){
    for(j = 0; j < ROLES_IN_GROUP; j++){
      if(test_person.role[i] == test_group.roles[j] && !checkedRole){
        counter--;
        checkedRole++;
      }
    }
  }
  return counter;
}

void fillGroups(const student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  int i, j, index = 0, tempBestValue, k, l, m = 0, roleExists  = 0, isNothing = 1;
  printf("error 102\n");
  for(i = 0; i < nrOfStudents; i++){
    for(j = 0; j < nrOfGroups; j++){
      printf("i = %i, j = %i\n", i , j);
      printf("calcBennefit = %i\n", calcBenefit(class[i], groups[j]));
      if(index < calcBenefit(class[i], groups[j])){
        
        printf("error 104\n");
        index = calcBenefit(class[i], groups[j]);
        tempBestValue = j;
        printf("error 103\n");
      }
      for (l = 0; l < ROLES_IN_STUDENT; l++) {
        isNothing = 1;
        m = 0;
        for(k = 0; k < ROLES_IN_GROUP; k++){
          if((groups[j].roles[k] != nothing) && (groups[j].roles[k] == class[i].role[l])){
            roleExists = 1;
          }
        }
        if (roleExists) {
          while (isNothing) {
            if (groups[j].roles[m] == nothing) {
              groups[j].roles[m] = class[i].role[l];
              isNothing = 0;
            }
          }
        }
      }

      groups[tempBestValue].students[groups[i].studentsInGroup] = class[i];
      groups[tempBestValue].studentsInGroup++;
    }
    index = 0;
  }
  printf("\n");




  printf("error 101\n");
  for(i = 0; i < nrOfGroups; i++){
    printf("gruppe %i har disse roller\n", i);
    for(j = 0; j < ROLES_IN_GROUP; j++){
      printf("rolle %i: %i\n", j, groups[i].roles[j]);
    }
    for(j = 0; j < groupSize; j++){
      printf("Elev %i: %i\n", j+1, groups[i].students[j].isStudent);
    }
  }
}
