#include <stdio.h>
#include <stdlib.h>

/*prototypes.h uses structs.h so they have to be loaded in this order*/
#include "structs.h"
/*#include "prototypes.h"*/

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
  int nrOfStudentsTeacherInput;
  int groupSize;
  int nrOfGroups;

//  dataSet = fopen("dataset", "r");

  teacherInput(&groupSize, &nrOfStudentsTeacherInput);
  nrOfStudents = countStudents(dataSet);
  class = allocateStudents(nrOfStudents);
  makeStudentArray(dataSet, nrOfStudents, class);
  allocateSizeGroups(nrOfStudents, groupSize, &groups, &nrOfGroups);
  fillGroups(class, groupSize, nrOfStudents, nrOfGroups, groups);

  do{
    resortNormies(groupSize, nrOfStudents, nrOfGroups, groups);
  } while (squaredError(groupSize, nrOfStudents, nrOfGroups, groups) > 1);

  printAll(groups, groupSize, nrOfGroups);
  return EXIT_SUCCESS;
}
