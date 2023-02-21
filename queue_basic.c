#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int rare = - 1;
int front = - 1;
int id=1;

struct Pizza
{
    int id,qnty;
    char name[50];
    char address[50];
    char ph[12];
} q[MAX];

int is_empty()
{
   if(front == - 1 || front > rare)
      return 1;
   else
      return 0;
}

int is_full() 
{
   if (rare==MAX-1)
      return 1;
   else
      return 0;
}

void insert()
{
    if (is_full())
    printf("\n Queue is full!! \n");
    else
    {
        if(front==-1) front=0;
        rare = rare + 1;
        q[rare].id=id++;
        printf("\nEnter the name: ");
        scanf("%s",q[rare].name);
        printf("Enter the address: ");
        scanf("%s",q[rare].address);
        printf("Enter the quantity: ");
        scanf("%d",&q[rare].qnty);
        printf("Enter the phone number: ");
        scanf("%s",q[rare].ph);
    }
}

void delete()
{
    if (is_empty())
    printf("\n Queue is empty !! \n");
    else 
    {
        printf("\nDelivered order is: ");
        printf("\n ID: %d",q[front].id);
        printf("\n Name: %s",q[front].name);
        printf("\n Address: %s",q[front].address);
        printf("\n Quantity: %d",q[front].qnty);
        printf("\n Phone: %s\n",q[front].ph);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rare; i++)
        {
            printf("\n ID: %d",q[i].id);
            printf("\n Name: %s",q[i].name);
            printf("\n Address: %s",q[i].address);
            printf("\n Quantity: %d",q[i].qnty);
            printf("\n Phone: %s",q[i].ph);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    }
    return 0;
}
 

