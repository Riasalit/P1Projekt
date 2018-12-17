void printAll(const group *groups, const int groupSize, const int nrOfGroups){
  int i, j;
  FILE *opf;
  opf = fopen("Groups-Complete.txt", "w");
  if(opf == NULL){
    printf("dataSet could not be found\n");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < nrOfGroups; i++){/*iterate through every group*/
    fprintf(opf,"\n--------------------------------------------------------\n Group %d\n--------------------------------------------------------\n", i+1);
    printf("\n Group %d score = %d\n--------------------------------------------------------\n", i+1, groups[i].amountOfRoles);/*print group number and score*/
    for(j = 0; j < groups[i].studentsInGroup; j++){/*iterate through every student in the group*/
      fprintf(opf, "%s\n", groups[i].students[j].name);
      printf("%s: roles = %d, %d, %d\n", groups[i].students[j].name,
                                         groups[i].students[j].role[0],
                                         groups[i].students[j].role[1],
                                         groups[i].students[j].role[2]);
    }/*print the name and all 3 roles for every student*/
  }
}
