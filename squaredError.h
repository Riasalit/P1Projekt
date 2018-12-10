double squaredError(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  int i, j;
  double  *error;
  double avg = 0, sqrdError = 0;

  error = calloc(nrOfGroups, sizeof(int));
  if (error == NULL){
    printf("ERROR: errors not allocated\n");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < nrOfGroups; i++){
    error[i] = ROLES_IN_GROUP;
    for (j = 0; j < ROLES_IN_GROUP; j++){
      if(groups[i].roles[j] != nothing) error[i] -= 1;
    }
    avg = ROLES_IN_GROUP - error[i];
    sqrdError += error[i] * error[i];
  }
  avg = avg/nrOfGroups;
  sqrdError = sqrdError/nrOfGroups;

  return (avg/sqrdError);
}
