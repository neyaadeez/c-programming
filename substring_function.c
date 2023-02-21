#include <stdio.h>
#include <stdlib.h>

void display(char str1[100]);
void accept(char str1[100]);  
int len(char str1[100]); 
int compare(char str1[100],char str2[100]);
void reverse(char str1[100],char str2[100]);
void subs(char str1[100],char str2[100]);


int main()
{
    int choice=0;
    char str1[100];
    char str2[100];
    while(1)
    {
        
        printf("1.Enter a string and display\n");
        printf("2.Enter a string and check it's length\n");
        printf("3.Compare two strings\n");
        printf("4.Reverse of a string\n");
        printf("5.Palindrome of a string\n");
        printf("6.Enter a string and find number of substrings\n");
        printf("7.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:printf("Enter string:\n");
               accept(str1);
               printf("Entered string is: \n");
               display(str1);
               break;
        case 2:printf("Enter string:\n");
               accept(str1);
               int l=0;
               l=len(str1);
               printf("Length of string is:%d \n",l);
               break;
        case 3:printf("Please enter first string:");
               accept(str1);
               printf("Please enter second string:");
               accept(str2);
               int y = compare(str1,str2);
                if(y==1)
               {
                   printf("%s is greater than %s \n",str1,str2);
               }
               else if(y==0)
               {
                   printf("%s is equal to %s \n",str1,str2);
               }
               else
               {
                   printf("%s is greater than %s \n",str2,str1);
               }
               break;
        case 4:printf("Please enter first string:");
               accept(str1);
               reverse(str1,str2);
               display(str2);
               break;
        case 5:printf("Enter a string");
               accept(str1);
               reverse(str1,str2);
               int x = compare(str1,str2);
               if(x==0)
               {
                   printf("String is palindrome\n");
               }
               else
               {
                   printf("String is not palindrome\n");
               }
               break;
        case 6:printf("Enter a string: \n");
               accept(str1);
               printf("Enter substring to search:\n");
               accept(str2);
               subs(str1,str2);
               break;
        case 7:exit(0);
        }
    }
    return 0;
}

void display(char str1[100])
{
    printf("%s",str1);
    printf("\n \n");
}

void accept(char str1[100])
{
    scanf("%s",str1);
}


int len(char str1[100])
{
    int l=0,i=0;
    while(str1[i]!='\0')
    {
        i++;
        l++;
    }
    return l;
}


int compare(char str1[100],char str2[100])
{
    int i=0;
    while((str1[i]==str2[i])&&(str1[i]!='\0'))
    {
        i++;
    }
    if(str1[i]>str2[i])
    {
        return 1;
    }
    else if(str1[i]==str2[i])
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void reverse(char str1[100],char str2[100])
{
    int l = len(str1)-1;
    int i = 0;
    while(l>=0)
    {
        str2[i]=str1[l];
        i++;
        l--;
    }
    str2[i]='\0';
}


void subs(char str1[100],char str2[100])
{
    int count1=0,count2=0,flag,cj=0,rj=0;
    while(str1[count1]!='\0')
    {
        count1++;
    }
    while(str2[count2]!='\0')
    {
        count2++;
    }
    for(int i=0; i<=count1; i++)
    {
        for(int j = i, rj=0; j<i+count2; j++, rj++)
        {
            if(str1[j]==str2[rj])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
cj++;
        }
    }
    if(cj!=0)
    {
        printf("The substring was found \n");
        printf("the substring occurs %d times \n",cj);
    }
    else
    {
        printf("Substring not found \n \n");
    }
}

