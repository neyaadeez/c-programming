#include<stdio.h>

int main() {
  char buffer[250];
  char xyz[250];
 
  printf("Enter the Information to be stored in file:\n");
  gets(xyz);
  FILE *fabc;
  fabc = fopen("try.txt", "w");
  fwrite(&xyz, sizeof(char), 250, fabc);
  fclose(fabc);

  fabc = fopen("try.txt", "r");
  fread(&buffer, sizeof(char), 250, fabc);
  printf("Reading text file: %s\n",buffer);
  fclose(fabc);

  return(0);
}