int calcBenefit(const student test_person, const group test_group){
  int counter = ROLES_IN_STUDENT;
  int i, j;
  for(i = 0; i < ROLES_IN_STUDENT; i++){
    for(j = 0; j < ROLES_IN_GROUP; j++){
      if(test_person.role[i] == test_group.roles[j]){
        counter--;
      }
    }
  }
  return counter;
}

void fillGroups(const student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  int i, j;
  printf("JEG ER SUPER GAY\n");
  for(i = 0; i < nrOfGroups; i++){
    for(j = 0; j < ROLES_IN_GROUP; j++){
      groups[i].roles[j] = nothing;
    }
  }
  printf("JEG ER SUPER mega GAY\n");
  for(i = 0; i < nrOfGroups; i++){
    printf("gruppe %i har disse roller\n", i);
    for(j = 0; j < ROLES_IN_GROUP; j++){
      printf("rolle %i: %i\n", j, groups[i].roles[j]);
    }
  }
  /* for(i = 0; i < nrOfStudents; i++){
    if(class[i].student.gfr)
      hvis den gør mere i en gruppe gem gruppens indeks
      set i gruppen den gjorde mest
  } */
}
