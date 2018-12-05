
typedef enum {nothing, ideskaber,
              specialist, analysator,
              organisator, opstarter,
              afslutter, formidler,
              koordinator, kontaktskaber} roles;

typedef struct{
  char name[30];
  int id;
  roles role[3];
} student;

typedef struct{
  student *students;
  int quality;
  roles roles[8];
} group;
