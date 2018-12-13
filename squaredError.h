double squaredError(const int groupSize, const int nrOfStudents, const int nrOfGroups, const group *groups){
  int i, j;
  double  *roles;
  double avg = 0, avgSqrdError = 0;
  double returnValue = 0;
  roles = calloc(nrOfGroups, sizeof(double));
  if (roles == NULL){
    printf("ERROR: errors not allocated\n");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < nrOfGroups; i++){
    roles[i] = 0;
    for (j = 0; j < ROLES_IN_GROUP; j++){
      if(groups[i].roles[j] != nothing) roles[i] += 1;
    }
    avg += roles[i];
  }
  avg = avg/nrOfGroups;
  for(i = 0; i < nrOfGroups; i++){
    avgSqrdError += (avg-roles[i])*(avg-roles[i]);
  }
  avgSqrdError = avgSqrdError/nrOfGroups;

  free(roles), roles = NULL;
  if(avgSqrdError != 0){
    returnValue = avg/avgSqrdError;
  } else {
    returnValue = avg/(1/(double)nrOfGroups+1);
  }
  return returnValue;
}
