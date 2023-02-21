#include<stdio.h>

struct Student
{
    int roll;
    char name[25];
    float marks;
};

void main()
{
    FILE *fptr1, *fptr2;
    char ch;
    struct Student a;

    fptr1 = fopen("Student.dat","w");

    if(fptr1 == NULL)
        {
            printf("\nCan't open file or file doesn't exist.");
            exit();
        }

    do
        {
            printf("\nEnter Roll : ");
            scanf("%d",&a.roll);

            printf("Enter Name : ");
            scanf("%s",a.name);

            printf("Enter Marks : ");
            scanf("%f",&a.marks);

            fwrite(&a,sizeof(a),1,fptr1);

            rintf("\nDo you want to add another data (y/n) : ");
            ch = getche();

        }while(ch=='y' || ch=='Y');

    printf("\nData written successfully...");
    
    
    fptr2 = fopen("Student.dat","r");

              if(fptr2 == NULL)
              {
                     printf("\nCan't open file or file doesn't exist.");
                     exit(0);
              }

              printf("\n\tRoll\tName\tMarks\n");

              while(fread(&a,sizeof(a),1,fptr2)>0)
                  printf("\n\t%d\t%s\t%f",a.roll,a.name,a.marks);

              fclose(fptr1);
              fclose(fptr2);
       }

