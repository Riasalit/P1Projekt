#include <stdio.h>
#include <stdlib.h>

void teacherInput(int *groupSize, int *nrOfStudents){
  int runLoop = 1;
  int ch;

  while(runLoop == 1){ /*loop until a number is entered*/
    printf("Type number of students: ");
    if((scanf("%d", nrOfStudents) == 1)){
      runLoop = 0;
    } else {
      runLoop = 1;
      printf("Not valid. Try again\n");
    }

    /*Clear input buffer to avoid infinite loop*/
    while((ch = getchar()) != '\n' && ch != EOF);
  }
  runLoop = 1;

  while(runLoop == 1){/*ask for size of groups until a number is entered*/
    printf("Type size of groups: ");
    if((scanf("%d", groupSize) == 1)){
      runLoop = 0;
    } else {
      runLoop = 1;
      printf("Not a valid group size. Try again\n");
    }
    /*Clear input buffer to avoid infinite loop*/
    while((ch = getchar()) != '\n' && ch != EOF);
  }
}
