#include <stdio.h>
#include <stdlib.h>

/*prototypes.h uses structs.h so they have to be loaded in this order*/ 
#include "structs.h"
#include "prototypes.h"

int main(void){
  student *class;
  group *groups;
  FILE *dataSet;
  int nrOfStudents;
  int groupSize;
  int nrOfGroups;

  dataSet = fopen("dataset", "r");

  teacherInput(&groupSize);
  nrOfStudents = countStudent(dataSet);
  class = allocateStudents(nrOfStudents);
  makeStudentArray(dataSet, nrOfStudents, class);
  groups = allocateSizeGroups(nrOfStudents, groupSize, &groups, &nrOfGroups);
  fillGroups(class, groupSize, nrOfStudents, nrOfGroups, groups);

  do{
    resortNormies(groupSize, nrOfStudents, nrOfGroups, groups);
  } while (squaredError(groupSize, nrOfStudents, nrOfGroups, groups) > 1);

  printAll(groups, groupSize, nrOfGroups);
  return EXIT_SUCCESS;
}

void teacherInput(int *groupSize){

}

int countStudent(FILE *dataSet){
  /*Skal rewinde til sidst*/
}

student *allocateStudents(const int nrOfStudents){
  /*nrOfStudents kommer fra countStudents*/
}

void makeStudentArray(const FILE *dataSet, const int nrOfStudents, student *class){
  /*nrOfStudents kommer fra countStudents*/

}

group *allocateSizeGroups(const int nrOfStudents, const int groupSize, group **groups, int *nrOfGroups){

}

void fillGroups(const student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  /*"for (hver student){
    hvis den gør mere i en gruppe gem gruppens indeks
    set i gruppen den gjorde mest
  }"*/
}

int squaredError(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
  /*find gennemsnit*/
  /*Kald i loop med resortNormies */
  /*return 0 er placeholder*/
  return 0;
}

void resortNormies(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups){
/*"take people out i who doesnt contribute for more than 1
and insert them into other groups where they do more" */
}

void printAll(const group *groups, const int groupSize, const int nrOfGroups){
 /*print grupperne*/
}
