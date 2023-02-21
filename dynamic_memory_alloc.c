#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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
        printf("\nEnter the data: ");
        scanf("%d",&curr->data);
        curr->next=NULL;
        temp->next=curr;
        temp=curr;
        printf("\nDo you want to continue ('y'/'n'): ");
        scanf(" %c",&ch);
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    if(temp->next==NULL)
    printf("\nLinked list is empty.\n");
    else
    {
        printf("\nLinked list values are: \n");
    while(temp->next!=NULL)
    {
        temp=temp->next;
        printf("-> %d\t", temp->data);
    }
    }
}

int len(struct node *head)
{
    int length;
    struct node *temp=head->next;
    if(temp==NULL)
    {
        printf("\nLinked list is empty.\n");
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        return length;
    }
}

void insertpos(struct node *head)
{
    struct node *temp=head;
    struct node *nnode;
    int i=1,pos,k;
    nnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &nnode->data);
    printf("\nEnter position to insert data: ");
    scanf("%d",&pos);
    k=len(head);
    if(pos>1+k)
        printf("\nCannot insert data since it is not in limit");
    else
    {
        while(temp!=NULL && i<pos)
        {
            i++;
            temp=temp->next;
        }
        nnode->next=temp->next;
        temp->next=nnode;
    }
    display(head);
}

void delpos(struct node *head)
{
    struct node *prev=head;
    struct node *curr, *temp;
    curr=head->next;
    int ctr=1,pos,k;
    printf("\nEnter position to delete data: ");
    scanf("%d",&pos);
    k=len(head);
    if(k<pos)
        printf("\nCannot delete data since it is not in limit");
    else
    {
        while(ctr<pos && curr!=NULL)
        {
            ctr++;
            prev=curr;
            curr=curr->next;
        }
        temp=curr;
        prev->next=curr->next;
        curr->next=NULL;
        free(temp);
    }
    display(head);
}

void reverse(struct node *head)
{
    struct node *prev, *curr, *future;
    prev=NULL;
    curr=head->next;
    while(curr!=NULL)
    {
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    head->next=prev;
    display(head);
}

void sort(struct node *head)
{
    int l = len(head);
    for(int i=0; i<l-1;i++)
    {
        struct node *prev = head->next;
        struct node *curr = head->next->next;
        for(int j=0; j<l-i-1; j++)
        {
            if(prev->data > curr->data)
            {
                int temp = prev->data;
                prev->data = curr->data;
                curr->data = temp;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    printf("Sorted List : ");
    display(head);
}

struct node* merge(struct node *head1, struct node *head2)
{
    int flag;
    struct node *curr1, *curr2, *temp;
    curr1=head1->next;
    curr2=head2->next;
    if(curr1->data<curr2->data)
    {
        temp=head1;  
        flag=1;
    }
    else
    {
        temp=head2;
        flag=0;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            temp->next=curr1;
            temp=curr1;
            curr1=curr1->next;
        }
        else
        {
            temp->next=curr2;
            temp=curr2;
            curr2=curr2->next;
        }
    }
    if(curr1==NULL)
    temp->next=curr2;
    if(curr2==NULL)
    temp->next=curr1;
    if(flag==1)
        return head1;
    else
        return head2;
}


int main()
{
    struct node *head, *head1, *f;
    head = (struct node *)malloc(sizeof(struct node));
    head->next=NULL;
    head1 = (struct node *)malloc(sizeof(struct node));
    head1->next=NULL;
    
    int ch;
    do
    {
        printf("\n1.Create List1\n");
        printf("2.Length\n");
        printf("3.Insert\n");
        printf("4.Delete\n");
        printf("5.Reverse\n");
        printf("6.Sort\n");
        printf("7.Create List2\n");
        printf("8.Merge List1 & List2\n");
        scanf("%d",&ch);
    
    switch(ch){
        
    case 1: {
                create(head);
                display(head);
                break;
            }
            
    case 2:{
                printf("\nLength of liked list is: %d",len(head));
                break;
            }
            
    case 3:{
                insertpos(head);
                break;
            }
            
    case 4:{
                delpos(head);
                break;
            }
            
    case 5:{
                reverse(head);
                break;
            }
    
    case 6:{
                printf("\nAfter sorting: ");
                sort(head);
                break;
            }
            
    case 7:{
    	        create(head1);
    	        display(head1);
    	        break;
            }
    case 8:{
                if(head->next==NULL || head1->next==NULL)
                    printf("\nList1 or/and List2 is empty.\n");
                else
                {
    	            f=merge(head, head1);
    	            sort(f);
                }
                break;
            }
    }
    }while(ch!=9);

    return 0;
}




