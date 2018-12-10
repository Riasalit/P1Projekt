#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*prototypes.h uses structs.h so they have to be loaded in this order*/
#include "structs.h"
/*#include "prototypes.h"*/
#include "sortGroups.h"

#include "teacherInput.h"
#include "countStudents.h"
#include "allocateStudents.h"
#include "makeStudentArray.h"
#include "allocateSizeGroups.h"
#include "fillGroups.h"
#include "squaredError.h"
#include "resortNormies.h"
#include "printAll.h"

int main(void){
  student *class;
  group *groups;
  FILE *dataSet;
  int nrOfStudents;
  int sentinel = 0;
  int groupSize;
  int nrOfGroups;

  dataSet = fopen("dataset", "r");
  if(dataSet == NULL){
    printf("dataSet could not be found\n");
    exit(EXIT_FAILURE);
  }

  while (!sentinel) {
    teacherInput(&groupSize, &nrOfStudents);
    sentinel = countStudents(dataSet, nrOfStudents);
    if(!sentinel){
      printf("Number of students doesn't match the input file\n");
    }
  }
  class = allocateStudents(nrOfStudents);
  makeStudentArray(dataSet, nrOfStudents, class);
  groups = allocateSizeGroups(nrOfStudents, groupSize, &nrOfGroups);
  sortedGroups = allocateSizeGroups(nrOfStudents, groupSize, &nrOfGroups);
  fillGroups(class, groupSize, nrOfStudents, nrOfGroups, groups);

  do{
    resortNormies(groupSize, nrOfStudents, nrOfGroups, groups);
  } while (squaredError(groupSize, nrOfStudents, nrOfGroups, groups) > 1);

  printAll(groups, groupSize, nrOfGroups);
  return EXIT_SUCCESS;
}
