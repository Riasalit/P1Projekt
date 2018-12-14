#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "sortGroups.h"

#include "teacherInput.h"
#include "countStudents.h"
#include "allocateStudents.h"
#include "makeStudentArray.h"
#include "allocateSizeGroups.h"
#include "allocateBestGroups.h"
#include "fillGroups.h"
#include "randomizeStudents.h"
#include "resortNormies.h"
#include "squaredError.h"
#include "printAll.h"

int main(void){
  student *class;
  group *groups, *sortedGroups;
  FILE *dataSet;
  int nrOfStudents;
  int sentinel = 0;
  int groupSize;
  int nrOfGroups;
  double currentSquaredError, bestSquaredError = 0;
  int attemptsLeft = MAX_ATTEMPTS;
  int i, j;

  srand(time(NULL));
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
  fclose(dataSet);
  groups = allocateSizeGroups(nrOfStudents, groupSize, &nrOfGroups);
  sortedGroups = allocateBestGroups(nrOfStudents, groupSize, nrOfGroups);
  fillGroups(class, groupSize, nrOfStudents, nrOfGroups, groups);
  do{
    resortNormies(groupSize, nrOfStudents, nrOfGroups, groups);
    currentSquaredError = squaredError(groupSize, nrOfStudents, nrOfGroups, groups);
    if (currentSquaredError > bestSquaredError){
      bestSquaredError = currentSquaredError;
      attemptsLeft = MAX_ATTEMPTS;
      for(i = 0; i < nrOfGroups; i++){
        for(j = 0; j < ROLES_IN_GROUP; j++){
          sortedGroups[i].roles[j] = groups[i].roles[j];
        }
        for(j = 0; j < groupSize; j++){
          sortedGroups[i].students[j] = groups[i].students[j];
        }
        sortedGroups[i].studentsInGroup = groups[i].studentsInGroup;
        sortedGroups[i].amountOfRoles = groups[i].amountOfRoles;
      }
    } else {
      attemptsLeft--;
    }
  } while (attemptsLeft > 0);
  printAll(sortedGroups, groupSize, nrOfGroups);
  for(i = 0; i < nrOfGroups; i++){
    free(groups[i].students), groups[i].students = NULL;
    free(sortedGroups[i].students), sortedGroups[i].students = NULL;
  }
  free(sortedGroups);
  free(groups);
  return EXIT_SUCCESS;
}
