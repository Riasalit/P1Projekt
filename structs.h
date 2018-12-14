#define ROLES_IN_GROUP 9
#define ROLES_IN_STUDENT 3
#define MAX_ATTEMPTS 5000

typedef enum {nothing, ideskaber,
              specialist, analysator,
              organisator, opstarter,
              afslutter, formidler,
              koordinator, kontaktskaber} roles; /*enum for every Belbin teamrole*/

typedef struct{
  int isStudent;/*is used as boolean value for arrays of students which hasn't been filled out yet*/
  char name[30];/*students name*/
  roles role[ROLES_IN_STUDENT]; /*The three main roles a student has*/
} student;

typedef struct{
  student *students;/*pointer meant to point to array of every student in group, dynamically allocated later*/
  int studentsInGroup; /*the amount of students in the group*/
  int amountOfRoles; /*the amount of unique roles represented in the group*/
  roles roles[ROLES_IN_GROUP]; /*array containing every unique role in a group*/
} group;
