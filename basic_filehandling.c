#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char f1[100], c;
    
    printf("Enter the file name to copy: ");
    scanf("%s", f1);
    
    fptr1=fopen(f1,"r");
    
    if(fptr1==NULL)
    {
        printf("\nUnable to open file");
        exit;
    }
    
    printf("Enter file to write: ");
    scanf("%s", f1);
    fptr2=fopen(f1,"w");
    
    if(fptr2==NULL)
    {
        printf("\nUnable to open file");
        exit;
    }
    
    c=fgetc(fptr1);
    
    while(c!=EOF)
    {
        fputc(c,fptr2);
        c=fgetc(fptr1);
    }
    
    printf("Contents copied");
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
