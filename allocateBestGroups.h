group *allocateBestGroups(const int nrOfStudents, const int groupSize, const int nrOfGroups){
  group *temp;
  int i;
  temp = NULL;
  temp = calloc(nrOfGroups, sizeof(group));
  if(temp == NULL){
    printf("ERROR: Could not create space for temp");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < nrOfGroups; i++){
    temp[i].students = NULL;
    temp[i].students = calloc(groupSize, sizeof(student));
    if(temp[i].students == NULL){
      printf("ERROR: Could not create space for temp[%d].student", i);
      exit(EXIT_FAILURE);
    }
  }

  return temp;
}
