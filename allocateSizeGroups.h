group *allocateSizeGroups(const int nrOfStudents, const int groupSize, int *nrOfGroups){
  group *temp;
  int i, k, j;
  temp = NULL;
  *nrOfGroups=nrOfStudents/groupSize;
  k = nrOfStudents%groupSize;
  if(k){
    *nrOfGroups += 1;
  }


  temp = calloc(*nrOfGroups, sizeof(group));
  if(temp == NULL){
    printf("ERROR: Could not create space for temp");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < *nrOfGroups; i++){
    temp[i].students = calloc(groupSize, sizeof(student));
    if(temp[i].students == NULL){
      printf("ERROR: Could not create space for temp[%d].student", i);
      exit(EXIT_FAILURE);
    }
  }
  for(i = 0; i < *nrOfGroups; i++){
    temp[i].quality = 0;
    temp[i].studentsInGroup = 0;
    for(j = 0; j < ROLES_IN_GROUP; j++){
      temp[i].roles[j] = nothing;
    }
    for(j = 0; j < groupSize; j++){
      temp[i].students[j].isStudent = 0;
    }
  }
  return temp;
}
