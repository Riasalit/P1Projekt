void printAll(const group *groups, const int groupSize, const int nrOfGroups){
  int i, j;
  for(i = 0; i < nrOfGroups; i++){/*iterate through every group*/
    printf("\n Group %d score = %d\n--------------------------------------------------------\n", i+1, groups[i].amountOfRoles);/*print group number and score*/
    for(j = 0; j < groups[i].studentsInGroup; j++){/*iterate through every student in the group*/
      printf("%s: roles = %d, %d, %d\n", groups[i].students[j].name,
                                         groups[i].students[j].role[0],
                                         groups[i].students[j].role[1],
                                         groups[i].students[j].role[2]);
    }/*print the name and all 3 roles for every student*/
  }
}
