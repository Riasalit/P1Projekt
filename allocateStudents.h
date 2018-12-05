student *allocateStudents(const int nrOfStudents){
  student *temp;
  temp = calloc(nrOfStudents, sizeof(student));
  if(temp == NULL){
    printf("ERROR: Could not create space for temp");
    exit(EXIT_FAILURE);
  }
  return temp;
}
