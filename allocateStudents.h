student *allocateStudents(const int nrOfStudents){
  student *temp;
  temp = calloc(nrOfStudents, sizeof(student));/*allocate space for every student*/
  if(temp == NULL){/*display error message if not enough space could be allocated and shut down program*/
    printf("ERROR: Could not create space for temp");
    exit(EXIT_FAILURE);
  }
  return temp;
}
