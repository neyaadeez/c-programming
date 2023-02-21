#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coff;
    int expo;
    struct node *next;
};

void create(struct node *head)
{
    struct node *temp, *curr;
    temp=head;
    char ch='y';
    while(ch=='y')
    {
        curr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient: ");
        scanf("%d",&curr->coff);
        printf("\nEnter exponent: ");
        scanf("%d",&curr->expo);
        curr->next=head;
        temp->next=curr;
        temp=curr;
        printf("\nDo you want to continue ('y'/'n'): ");
        scanf(" %c",&ch);
    }
}

struct node* addit(struct node *h1, struct node *h2)
{
    struct node *h3, *t1, *t2, *t3, *temp;
    h3=(struct node *)malloc(sizeof(struct node));
    h3->next=h3;
    h3->expo=-1;
    t3=h3;
    t1=h1->next;
    t2=h2->next;
    while(t1->expo!=-1||t2->expo!=-1)
    {
        if(t1->expo==t2->expo)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->coff=t2->coff+t1->coff;
            temp->expo=t1->expo;
            temp->next=h3;
            t3->next=temp;
            t3=temp;
            t2=t2->next;
            t1=t1->next;
        }
        
        else if(t1->expo<t2->expo)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->coff=t2->coff;
            temp->expo=t2->expo;
            temp->next=h3;
            t3->next=temp;
            t3=temp;
            t2=t2->next;
        }
        
        else
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->coff=t1->coff;
            temp->expo=t1->expo;
            temp->next=h3;
            t3->next=temp;
            t3=temp;
            t1=t1->next;
        }
    }
    return h3;
}

void eval(struct node *head, int x)
{
    int y=0,t=0;
    struct node *curr;
    curr=head->next;
    while(curr->expo != -1)
    {
        t=(curr->coff*pow(x,curr->expo));
        y=y+t;
        curr=curr->next;
    }
    printf("Evaluated: %d\n",y);
}


void display(struct node *head) 
{
    printf("\nThe polynomial expression is:\n");
    struct node *curr;
    curr=head;
    while(curr->next != head)
    {
        curr = curr->next;
        printf("%dx^%d", curr->coff, curr->expo);
            printf(" + ");
    }
    printf("\n");
}


int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    head->next = head;
    head1->next = head1;
    head1->expo=-1;
    head->expo=-1;
    int choice = 0;
    int l, x;
    
    while(1)
    {
        printf("\n Enter choice as follows:\n 1.Create List\n 2.Display List\n 3.Add Two Polynomials \n 4.Evaluate Polynomial\n 5.Exit Program\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : 
                    create(head);
                    break;
            case 2: 
                    printf("\n Linked list is: ");
                    display(head);
                    break;
            case 3:
                    printf("\n Accepting Linked list 1:");
                    create(head);
                    printf("\n Accepting Linked list 2:");
                    create(head1);
                    printf("\n List 1: ");
                    display(head);
                    printf("\n List 2: ");
                    display(head1);
                    printf("\n Is given as:");
                    struct node* m = addit(head, head1);
                    display(m);
                    break;
            case 4:
                    printf("\n Accepting Linked list for Evaluation: ");
                    create(head);
                    printf("\n Enter the value of X: ");
                    scanf("%d", &x);
                    eval(head,x);
                    break;
            case 5:
                    printf("\n Exit program\n");
                    exit(0);
                    break;
            default:
                    printf(" %d is an invalid input. Please retry\n",choice);
                    break;
        }
    }
    return 0;
}
