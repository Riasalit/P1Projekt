int groupSortFunc(const void *p1, const void *p2){
  student *student1 = (student *) p1;
  student *student2 = (student *) p2;
  if(student1->isStudent == 1 && student2->isStudent == 0){
    return -1;
  }else if(student1->isStudent == 0 && student2->isStudent == 1){
    return 1;
  }else{
    return 0;
  }
}


void sortGroups(const int nrOfGroups, const int groupSize, group *groups){
  int i;
  for(i = 0; i < nrOfGroups; i++){
    qsort(groups[i].students, groupSize, sizeof(student), groupSortFunc);
  }
}
