/*PROTOTYPES*/
void teacherInput(int *groupSize);
int countStudent(FILE *dataSet);
student *allocateStudents(const int nrOfStudents);
void makeStudentArray(const FILE *dataSet, const int nrOfStudents, student *class);
group *allocateSizeGroups(const int nrOfStudents, const int groupSize, group **groups, int *nrOfGroups);
void fillGroups(const student *class, const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups);
int squaredError(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups);
void resortNormies(const int groupSize, const int nrOfStudents, const int nrOfGroups, group *groups);
void printAll(const group *groups, const int groupSize, const int nrOfGroups);
