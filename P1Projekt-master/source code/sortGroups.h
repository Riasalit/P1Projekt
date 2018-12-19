int groupSortFunc(const void *p1, const void *p2){/*qsort compare function*/
  student *student1 = (student *) p1;
  student *student2 = (student *) p2;
  if(student1->isStudent == 1 && student2->isStudent == 0){/*return -1 if student is a student, putting all spaces in a
    group which hasn't been assigned a student at the bottom*/
    return -1;
  }else if(student1->isStudent == 0 && student2->isStudent == 1){
    return 1;
  }else{
    return 0;
  }
}


void sortGroups(const int nrOfGroups, const int groupSize, group *groups){/*calls qsort with groupSortFunc for every group in array of groups*/
  int i;
  for(i = 0; i < nrOfGroups; i++){
    qsort(groups[i].students, groupSize, sizeof(student), groupSortFunc);
  }
}
