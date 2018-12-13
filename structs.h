#define ROLES_IN_GROUP 9
#define ROLES_IN_STUDENT 3
#define MAX_ATTEMPTS 5000

typedef enum {nothing, ideskaber,
              specialist, analysator,
              organisator, opstarter,
              afslutter, formidler,
              koordinator, kontaktskaber} roles;

typedef struct{
  int isStudent;
  char name[30];
  int id;
  roles role[ROLES_IN_STUDENT];
} student;

typedef struct{
  student *students;
  int quality;
  int studentsInGroup;
  int amountOfRoles;
  roles roles[ROLES_IN_GROUP];
} group;
