#include <stdio.h>
struct student
{
    char Name[50];
    int roll;
    float marks;
    char Div[10];
};

void bubble(struct student s[30], int n);
void input(struct student s[30], int n);
void accept(struct student s[30], int n);
void display(struct student s[30], int n);
void linear(struct student s[30], int n);
void binary(struct student s[30], int n);
int binaryr(struct student s[30], int low, int high, int key);
void selection(struct student s[30], int n);
void insertion(struct student s[30], int n);

void bubble(struct student s[30], int n)
{
    int i, j;
    struct student temp;
    for(j=0; j<n; j++)
    {
        for(i=0; i<n-1; i++)
        {
            if(s[i].roll>s[i+1].roll)
            {
                temp=s[i+1];
                s[i+1]=s[i];
                s[i]=temp;
            }
        }
    }
}


void input(struct student s[30], int n)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        printf("Enter the name of the student: \n");
        scanf("%s", s[i].Name);
        printf("Enter roll number: \n");
        scanf("%d", &s[i].roll);
        printf("Enter marks: \n");
        scanf("%f", &s[i].marks);
        printf("Enter division: \n");
        scanf("%s", s[i].Div);
    }
}

void accept(struct student s[30], int n)
{
    int i=n;
        printf("Enter the name of the student: \n");
        scanf("%s", s[i].Name);
        printf("Enter roll number: \n");
        scanf("%d", &s[i].roll);
        printf("Enter marks: \n");
        scanf("%f", &s[i].marks);
        printf("Enter division: \n");
        scanf("%s", s[i].Div);
}

void display(struct student s[30], int n)
{
    printf("\nName: %s", s[n].Name);
    printf("\nRoll No.: %d", s[n].roll);
    printf("\nMarks: %f", s[n].marks);
    printf("\nDivision: %s", s[n].Div);
}

void linear(struct student s[30], int n)
{
    int key;
    int flag=0;
    int i=0;
    int ptr=0;
    printf("\nEnter the roll number: ");
    scanf("%d", &key);
    for(i=0; i<n; i++)
    {
        if(s[i].roll==key)
        {
            flag=1;
            ptr=i;
        }
    }
    if(flag==1)
    {
        printf("\nRoll number found.\n");
        display(s,ptr);
    }
    else
    {
        printf("\nRoll number not found!! \n\n");
    }
}

void binary(struct student s[30], int n)
{
    int low=0, mid, high=n, key, flag=0;
    printf("\nEnter the roll number: ");
    scanf("%d", &key);
    mid=(low+high)/2;
    while(low<=high)
    {
        if(s[mid].roll==key)
        {
            printf("\nRoll number found: \n");
            display(s,mid);
            flag=1;
            break;
        }
        else if(s[mid].roll>key)
            high=mid-1;
        else if(s[mid].roll<key)
            low=mid+1;
        mid=(low+high)/2;
    }
    if(flag==0)
        printf("\nRoll number not found!!\n\n");
}

int binaryr(struct student s[30], int low, int high, int key)
{
    int mid=0;
    mid=(low+high)/2;
    if(low<=high)
    {
        if(s[mid].roll==key)
            return mid;
        else if(s[mid].roll>key)
            return binaryr(s, low, mid-1, key);
        else if(s[mid].roll<key)
            return binaryr(s, mid+1, high, key);
    }
    return -1;
}

void insertion(struct student s[30], int n)
{
    int i, j;
    struct student key;
    for(i=1; i<n; i++)
    {
        key=s[i];
        j=i-1;
        while(j>=0 && s[j].roll>key.roll)
        {
            s[j+1]=s[j];
            j=j-1;
        }
        s[j+1]=key;
    }
}

void selection(struct student s[30], int n)
{
    int i, j, min;
    struct student temp;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(s[j].roll<s[min].roll)
                min=j;
        }
    temp=s[min];
    s[min]=s[i];
    s[i]=temp;
    }
}





int main()
{
    int n, f, key, ch, i;
    struct student s[30];
    struct student s1[30];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int low=0, high=n;
    input(s,n);
    do
    {
        printf("\n1. Search roll number using linear search\n");
        printf("2. Search roll number using binary search\n");
        printf("3. Search roll number using binary recursive search\n");
        printf("4. Bubble sort\n");
        printf("5. Selection sort\n");
        printf("6. Insertion sort\n");
        printf("7. Display list\n");
        printf("8. Add a record\n");
        printf("9. Exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                    linear(s,n);
                    break;
            case 2:
                    bubble(s,n);
                    binary(s,n);
                    break;
            case 3:
                    printf("\nEnter the roll number to be searched: ");
                    scanf("%d", &key);
                    bubble(s,n);
                    f=binaryr(s,low,high,key);
                    if(f==-1)
                        printf("\nRoll number not found!!\n\n");
                    else
                    {
                        printf("\nRoll number found\n");
                        display(s,f);
                    }
                    break;
            case 4:
                    bubble(s,n);
                    printf("\nSorted using bubble sort\n");
                    break;
            case 5:
                    selection(s,n);
                    printf("\nSorted using selection sort\n");
                    break;
            case 6:
                    insertion(s,n);
                    printf("\nSorted using insertion sort\n");
                    break;
            case 7:
                    for(i=0; i<n; i++)
                    {
                        display(s,i);
                        printf("\n\n");
                    }
                    break;
            case 8:
                   accept(s,n);
                   n++;
                   break;
        }
    }while(ch!=9);
    
    return 0;
}



