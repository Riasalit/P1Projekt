group *allocateBestGroups(const int nrOfStudents, const int groupSize, const int nrOfGroups){
  group *temp;
  int i;
  temp = NULL;
  temp = calloc(nrOfGroups, sizeof(group));/*allocates space for all the groups needed*/
  if(temp == NULL){/*display error message if not enough space could be allocated and shut down program*/
    printf("ERROR: Could not create space for temp\n");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < nrOfGroups; i++){/*iterate through all the groups*/
    temp[i].students = NULL;/*makes a student into NULL pointer*/
    temp[i].students = calloc(groupSize, sizeof(student));/*allocates space for every student*/
    if(temp[i].students == NULL){/*display error message if not enough space could be allocated and shut down program*/
      printf("ERROR: Could not create space for temp[%d].student\n", i);
      exit(EXIT_FAILURE);
    }
  }

  return temp;
}
