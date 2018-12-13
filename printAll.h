void printAll(const group *groups, const int groupSize, const int nrOfGroups){
  int i, j;
  int score;

  for(i = 0; i < nrOfGroups; i++){
    score = 0;
    for(j = 0; j < ROLES_IN_GROUP; j++){
      if(groups[i].roles[j] != nothing) score++;
      printf("group %d role %d = %d\n", i+1, j, groups[i].roles[j]);
    }
    printf("\n Group %d score = %d\n--------------------------------------------------------\n", i+1, score);
    for(j = 0; j < groups[i].studentsInGroup; j++){
      printf("%s: roles = %d, %d, %d\n", groups[i].students[j].name,
                                         groups[i].students[j].role[0],
                                         groups[i].students[j].role[1],
                                         groups[i].students[j].role[2]);

    }
  }
}
