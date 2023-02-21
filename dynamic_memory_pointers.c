# include <stdio.h>
# include <stdlib.h>


struct node
{
    int data;
    struct node* next;
};


void create (struct node* head);
void display(struct node* head);
 int length (struct node* head);
void insert(struct node* head);
void delete(struct node* head);
void reverse(struct node* head);
void bubbleSort(struct node *head); 
void swap(struct node *a, struct node *b); 
struct node* merge(struct node* head, struct node* head1);


int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    head1->next = NULL;
    int choice = 0;
    int l;
    
    while(1)
    {
        printf("\n Enter choice as follows:\n 1.Create List\n 2.Display List\n 3.Length of List\n 4.Insert by position\n 5.Delete by position\n 6.Reverse\n 7.Bubble Sort \n 8.Merge sort 2 linked lists\n 9.Exit\n");
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
                    l = length(head);
                    printf("\n Length of linked list is: %d\n",l);
                    break;
            case 4: 
                    insert(head);
                    printf("\n After insertion linked list is: ");
                    display(head);
                    break;
            case 5: 
                    delete(head);
                    printf("\n After deletion linked list is: ");
                    display(head);
                    break;
            case 6: 
                    printf("\n Original linked list is: ");
                    display(head);
                    printf("\n Reversed list is: ");
                    reverse(head);
                    break;
            case 7: 
                    printf("\n Unsorted linked list is: ");
                    display(head);
                    bubbleSort(head);
                    
	                printf("\n Sorted linked list is: ");
	                display(head);
                    break;
            case 8:
                    printf("\n Accepting Linked list 1:");
                    create(head);
                    printf("\n Accepting Linked list 2:");
                    create(head1);
                    printf("\n Merge sort of:");
                    printf("\n List 1: ");
                    display(head);
                    printf("\n List 2: ");
                    display(head1);
                    printf("\n Is given as:");
                    struct node* mergedhead = merge(head, head1);
                    display(mergedhead);
                    break;
            case 9: //Exit program
                    printf("\n Exit program\n");
                    exit(0);
                    break;
            default:printf(" %d is an invalid input. Please retry\n",choice);
                    break;
        }
    }
    
    return 0;
}


void create(struct node* head)
{
    char ch;
    struct node *temp = head;
    struct node *curr;
    do
    {
       curr = (struct node*)malloc(sizeof(struct node));
      
       printf("\n Enter Data: ");
       scanf("%d",&curr->data);
       
       temp -> next = curr;
       temp = curr;
       printf(" Enter y to continue or n to stop:\n ");
       scanf(" %c",&ch);
    }
    while(ch=='y');
}


void display(struct node* head)
{
    char ch;
    struct node *curr = head->next;

    
    if(curr == NULL)
    {
        printf("\n List is empty!");
    }
    
  
    else
    {
        while(curr != NULL)
        {
            printf("%d->",curr->data);
            curr=curr->next;
        }
        printf("\n");
    }
}  


int length (struct node* head)
{
    char ch;
    struct node *curr = head->next;
    int len;
    
    
    if(curr == NULL)
    {
        printf("\n List is empty!");
        return 0;
    }
    
    
    else
    {
        while(curr != NULL)
        {
            len ++;
            curr=curr->next;
        }
    }
    return len;
} 


void insert(struct node* head)
{
    int j=1;
    int k;
    int pos;
    int len = length(head);
    struct node *curr = head;
    struct node *nnode;
    
   
    nnode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter Data: ");
    scanf("%d",&nnode->data);
    printf("\n Enter position number to insert data: ");
    scanf("%d",&pos);
    
    
    if (pos <= (len+1))
    {
        while(curr!=NULL  && j<pos)
        {
            j++;
            curr=curr->next;
        }
    nnode->next = curr->next;
    curr->next=nnode;
    } 
    
    
    else
    {
        printf(" %d is greater than %d\n",pos,len);
        printf("\n Data can't be inserted!");
    }
}


void delete(struct node* head)
{
    struct node *prev = head;
    struct node *temp;
    int ctr =1;
    int pos1;
    int len = length(head);
    
    struct node *curr = head->next;
    printf("\n Enter position number to be deleted: ");
    scanf("%d",&pos1);
    

    if(len < pos1)
    {
        printf(" %d position not found!\n",pos1);
        printf("\n Data cannot be deleted!\n");
    }

    else
    {
        while(ctr<pos1 && curr!=NULL)
        {
            ctr++;
            prev = curr;
            curr = curr->next;
        }
    temp = curr;
    prev->next = curr->next;
    curr->next = NULL;
    
    
    free(temp); 
    }
}


void reverse(struct node* head)
{
    
    struct node *prev = NULL;
    struct node *curr = head->next;
    struct node *future;
    struct node *t = head;
    
    while(curr != NULL)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    
    head->next = prev;
    
    
    t = head->next;
	while(t != NULL)
	{
		printf("%d->",t->data);
		t = t->next;
	}
}


void bubbleSort(struct node *head) 
{ 
    
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
   
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
           
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  

void swap(struct node *a, struct node *b) 
{ 
    
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
}


struct node* merge(struct node* head, struct node* head1) 
{ 
   
    if (!head) 
        return head1; 
    if (!head1) 
        return head; 
  
    
    if (head->data <= head1->data) 
    { 
        head->next = merge(head->next, head1); 
        return head; 
    } 
    else 
    { 
        
        head1->next = merge(head, head1->next); 
        return head1; 
    } 
}
