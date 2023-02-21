#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int num_arr[10], n;

void ascending()
{
    int i, j, temp;
    for(j=0; j<n; j++)
    {
        for(i=0; i<n-1; i++)
        {
            if(num_arr[i]>num_arr[i+1])
            {
                temp=num_arr[i+1];
                num_arr[i+1]=num_arr[i];
                num_arr[i]=temp;
            }
        }
    }
    printf("\n-----Elements in Ascending Order-----");
    for(i=0;i<n;i++)
    {
        printf("\n %d \n",num_arr[i]);
    }
}

void descending()
{
    int i, j, temp;
    for(j=0; j<n; j++)
    {
        for(i=0; i<n-1; i++)
        {
            if(num_arr[i]<num_arr[i+1])
            {
                temp=num_arr[i+1];
                num_arr[i+1]=num_arr[i];
                num_arr[i]=temp;
            }
        }
    }
    printf("\n-----Elements in Descending Order-----");
    for(i=0;i<n;i++)
    {
        printf("\n %d \n",num_arr[i]);
    }
}



int main()
{
    pid_t num_pid;
    int status, i, j;
    
    printf("Enter the number of elements for sorting: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num_arr[i]);
    }
    
    num_pid=fork();
    
    if(num_pid==0)
    {
        printf("\nParent process id: %d\n", getppid());
        printf("\nChild process id: %d\n", getpid());
        printf("\n\n-----Child Process is Executing-----");
        descending();
        exit(10);
    }
    if(num_pid>0)
    {
        wait(&status);
        printf("\nParent allowed child to finish and got exit status");
        printf("\nExit status of child: %d", WEXITSTATUS(status));
        
        printf("\n\n-----Parent Process is Executing-----");
        ascending();
    }
    else
        printf("\nError is fork");
    return 0;
}





