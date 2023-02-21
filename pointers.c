#include<stdio.h>
#include<stdlib.h>

void display(char str[100]);
void accept(char str[100]);
int length(char str[100]);
void copy(char str[100], char str1[100]);
void concate(char str[100], char str1[100]);

int length1(char *ptr);
void copy1(char *ptr, char *ptr1);
void concate1(char *ptr, char *ptr1);


int main()
{
    int choice=0,l,l1;
    char str[100], str1[100];
    while(1)
    {
        printf("1. Enter a string and display.\n");
        printf("2. Enetr a string and check its length without pointer.\n");
        printf("3. Enter a string and display copied string.\n");
        printf("4. Enter a string and display concat string.\n");
        
        printf("5. Enetr a string and check its length with pointer.\n");
        printf("6. Enter a string and display copied string with pointer.\n");
        printf("7. Enter a string and display concat string with pointer.\n");
        printf("8. Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                accept(str);
                printf("\nThe string entered: ");
                display(str);
                break;
            case 2:
                printf("Enter a string: ");
                accept(str);
                l=length(str);
                printf("\nLength of the string is %d",l);
                printf("\n");
                break;
            case 3:
                printf("Enter a string: ");
                accept(str);
                copy(str,str1);
                printf("\nCopied string: ");
                display(str1);
                break;
            case 4:
                printf("Enter first string: ");
                accept(str);
                printf("\nEnter second string: ");
                accept(str1);
                concate(str,str1);
                printf("\nConcat string is: ");
                display(str);
                break;
            case 5:
                printf("Enter a string: ");
                accept(str);
                l1=length1(str);
                printf("\nLength of the string is %d",l1);
                printf("\n");
                break;
            case 6: 
                printf("Enter a string: ");
                accept(str);
                copy1(str,str1);
                printf("\nCopied string: ");
                display(str1);
                break;
            case 7:
                printf("Enter first string: ");
                accept(str);
                printf("\nEnter second string: ");
                accept(str1);
                concate1(str,str1);
                printf("\nConcat string is: ");
                display(str);
                break;
            case 8:
                exit(0);
            
        }
    }

    return 0;
}


void display(char str[100])
{
    printf("%s",str);
    printf("\n");
}

void accept(char str[100])
{
    scanf("%s",str);
}

int length(char str[100])
{
    int l=0, i=0;
    while(str[i]!='\0')
    {
        i++;
        l++;
    }
    return l;
}

int length1(char *ptr)
{
    int count=0;
    while(*ptr!='\0')
    {
        count++;
        ptr++;
    }
    return count;
}

void copy(char str[100], char str1[100])
{
    int i=0;
    while(str[i]!='\0')
    {
        str1[i]=str[i];
        i++;
    }
    str1[i]='\0';
}

void copy1(char *ptr, char *ptr1)
{
    while(*ptr!='\0')
    {
        *ptr1=*ptr;
        ptr++;
        ptr1++;
    }
    *ptr1='\0';
}

void concate(char str[100], char str1[100])
{
    int i=0,j;
    j=length(str);
    while(str1[i]!='\0')
    {
        str[j]=str1[i];
        i++;
        j++;
    }
    str[j]='\0';
}

void concate1(char *ptr, char *ptr1)
{
    int v=0;
    v=length1(ptr);
    ptr=ptr+v;
    while(*ptr1!='\0')
    {
        *ptr=*ptr1;
        ptr++;
        ptr1++;
    }
    *ptr='\0';
}
