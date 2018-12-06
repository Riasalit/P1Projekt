int countStudents(FILE *dataSet, const int nrOfStudents){
  int countLines = 0;
  int ch;

  /*Check if the file pointer equals null. If not, count each line shift as long as the file hasn't reached its end */
  while((ch = fgetc(dataSet)) != EOF){
    if(ch == '\n'){
      countLines++;
    }
  }
  /*Rewind pointer from the end of the file to the starting point*/
  rewind(dataSet);
  return countLines == nrOfStudents;
}
