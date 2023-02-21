#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int rare=-1;             
int front=-1;                 
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
   if(front == -1)
      return 1;
   else
      return 0;
}

int is_full() 
{
   if ((front==rare+1)||(front==0 && rare==MAX-1))
      return 1;
   else
      return 0;
}

void display()
{
        int i;
        if(is_empty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nThe orders are: ");
        i=front;
        if( front<=rare )
        {
                while(i<=rare)
                        {
                            printf("\n ID: %d",q[i].id);
                            printf("\n Name: %s",q[i].name);
                            printf("\n Address: %s",q[i].address);
                            printf("\n Quantity: %d",q[i].qnty);
                            printf("\n Phone: %s",q[i].ph);
                            i++;
                        }
        }
        else
        {
                while(i<=MAX-1)
                        {
                            printf("\n ID: %d",q[i].id);
                            printf("\n Name: %s",q[i].name);
                            printf("\n Address: %s",q[i].address);
                            printf("\n Quantity: %d",q[i].qnty);
                            printf("\n Phone: %s",q[i].ph);
                            i++;
                        }
                i=0;
                while(i<=rare)
                        {
                            printf("\n ID: %d",q[i].id);
                            printf("\n Name: %s",q[i].name);
                            printf("\n Address: %s",q[i].address);
                            printf("\n Quantity: %d",q[i].qnty);
                            printf("\n Phone: %s",q[i].ph);
                            i++;
                        }
        }
        printf("\n");
}

void deliver()
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
        printf("\n Phone: %s",q[front].ph);
        
        if (front==rare)
        {
            front=-1;
            rare=-1;
        } 
        else 
        {
            front=(front+1)%MAX;
        }
    }
}
void accept()
{
    if (is_full())
    printf("\n Queue is full!! \n");
    else
    {
        if (front == -1) front = 0;
        rare = (rare + 1) % MAX;
        q[rare].id=id++;
        printf("Enter the name: ");
        scanf("%s",q[rare].name);
        printf("Enter the address: ");
        scanf("%s",q[rare].address);
        printf("Enter the quantity: ");
        scanf("%d",&q[rare].qnty);
        printf("Enter the phone number: ");
        scanf("%s",q[rare].ph);
    }
}


int main()
{
    int ch=0;
    do
    {
    printf("\n1.Accept order\n2.Dispatch the order\n3.Display orders\n4.Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            accept();
            break;
        }
        case 2:
        {
            deliver();
            break;
        }
        case 3:
        {
            display();
            break;
        }
    }
    }while(ch!=4);   
    return 0;
}



