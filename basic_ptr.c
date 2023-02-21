#include<stdio.h>
#include<stdlib.h>
void copy(char*, char*);

int main()
{
    char source[50], target[50];    
    printf("Enter source string\n");    
    gets(source);    
    copy(source, target);    
    printf("Target string is \"%s\"\n", target); 
    return 0;
}

void copy(char *ptr1, char *ptr2)
{
  while(*ptr2++ = *ptr1++)
  {}
}

