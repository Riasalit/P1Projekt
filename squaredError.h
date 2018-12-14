double squaredError(const int groupSize, const int nrOfStudents, const int nrOfGroups, const group *groups){
  int i, j;
  double  *roles;
  double avg = 0, avgSqrdError = 0;
  double returnValue = 0;
  roles = calloc(nrOfGroups, sizeof(double)); /* create an int or each group in an array */
  if (roles == NULL){
    printf("ERROR: errors not allocated\n");
    exit(EXIT_FAILURE);
  }
/* count all the roles in each group and add the count roles[] and then add the number to avg */
  for(i = 0; i < nrOfGroups; i++){
    roles[i] = groups[i].amountOfRoles;
    avg += roles[i];
  }
  avg = avg/nrOfGroups; /* divide avg with the number of groups to get the actual average */

  /* add the squared error for each group to a collected integer */
  for(i = 0; i < nrOfGroups; i++){
    avgSqrdError += (avg-roles[i])*(avg-roles[i]);
  }
  avgSqrdError = avgSqrdError/nrOfGroups; /* get the average of the squared errors */

  free(roles), roles = NULL;
  /* create a value that symbolises the quality of the group */
  if(avgSqrdError != 0){
    returnValue = avg/avgSqrdError;
  } else {
    returnValue = avg/(1/((double)nrOfGroups)+1);
  }
  return returnValue;
}
