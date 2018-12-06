roles stringToRole(char *input){
  if(strcmp(input, "ideskaber") == 0){
    return ideskaber;
  }else if(strcmp(input, "specialist") == 0){
    return specialist;
  }else if(strcmp(input, "analysator") == 0){
    return analysator;
  }else if(strcmp(input, "organisator") == 0){
    return organisator;
  }else if(strcmp(input, "opstarter") == 0){
    return opstarter;
  }else if(strcmp(input, "afslutter") == 0){
    return afslutter;
  }else if(strcmp(input, "formidler") == 0){
    return formidler;
  }else if(strcmp(input, "koordinator") == 0){
    return koordinator;
  }else if(strcmp(input, "kontaktskaber") == 0){
    return kontaktskaber;
  }else{
    return nothing;
  }
}

void makeStudentArray(FILE *dataSet, const int nrOfStudents, student *class){
  int i;
  char temp1[30], temp2[30], temp3[30];
  for (i = 0; i < nrOfStudents; i++){
    class[i].id = i;
    fscanf(dataSet, " %[^:]: %s %s %s", class[i].name,
                                        temp1,
                                        temp2,
                                        temp3);
    class[i].role[0] = stringToRole(temp1);
    class[i].role[1] = stringToRole(temp2);
    class[i].role[2] = stringToRole(temp3);
  }
}
