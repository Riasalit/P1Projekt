group *allocateSizeGroups(const int nrOfStudents, const int groupSize, int *nrOfGroups){
  group *temp;
  int i, k, j;
  temp = NULL;
  *nrOfGroups=nrOfStudents/groupSize;/*calculates the amount of groups needed based on the teacher input and the amount of students
  if it is not possible to have equal number of students in every group, make one more group to have enough*/
  k = nrOfStudents%groupSize;
  if(k){
    *nrOfGroups += 1;
  }


  temp = calloc(*nrOfGroups, sizeof(group));/*allocate space for all the groups*/
  if(temp == NULL){/*display error message if not enough space could be allocated and shut down program*/
    printf("ERROR: Could not create space for temp\n");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < *nrOfGroups; i++){/*iterate through all groups*/
    temp[i].students = NULL;
    temp[i].students = calloc(groupSize, sizeof(student));/*allocate space for the students in the group*/
    if(temp[i].students == NULL){/*display error message if not enough space could be allocated and shut down program*/
      printf("ERROR: Could not create space for temp[%d].student\n", i);
      exit(EXIT_FAILURE);
    }
  }
  for(i = 0; i < *nrOfGroups; i++){/*iterate through all groups again*/
    temp[i].amountOfRoles = 0;
    temp[i].studentsInGroup = 0;/*assigns 0 to studentsInGroup to avoid undefined behaviour*/
    for(j = 0; j < ROLES_IN_GROUP; j++){/*for every role in the array meant to contain all the roles in the group*/
      temp[i].roles[j] = nothing;/*set all the roles to nothing, for checking if the group has any roles*/
    }
    for(j = 0; j < groupSize; j++){ /*for every student in the group*/
      temp[i].students[j].isStudent = 0;/*sets every student to not be a student, since no actual student has been assigned yet*/
      for(k = 0; k < ROLES_IN_STUDENT; k++){/*iterate through every role the student has*/
        temp[i].students[j].role[k] = nothing;/*sets every role to nothing, since the students roles hasnt been assigned yet*/
      }
    }
  }
  return temp;
}
