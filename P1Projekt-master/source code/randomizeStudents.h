int randomAlg(const void *p1, const void *p2){
  return (rand()%3)-1;
}

void randomizeStudents(const int amount, student *students){
  qsort(students, amount, sizeof(student), randomAlg);
}
