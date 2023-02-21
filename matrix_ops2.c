#include <stdio.h>

void accept(int a[10][10],int r,int c)
{
	int i,j;
	printf("\nenter elements of matrix A row by row\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void Display(int a[10][10],int r,int c)
{
	int i,j;
	printf("The Matrix formed is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]); 
		}
		printf("\n");
	}
}

void displaycom(int A[20][3], int m, int n)
{
    int i=0,j=0;
    printf("\nmatrix: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}

void compact(int a[10][10],int r,int c,int b[20][3])
{
	int i,j,k=1;
	b[0][0]=r;
	b[0][1]=c;
		for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
	    }      
	    b[0][2]=k-1;
   }
 	int column=b[0][2];
   printf("Compact: \n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
   }
}

void Transpose(int b[20][3],int c1[20][3])
{ 
	int t=b[0][2];
	int m=b[0][0];
	int n=b[0][1];
	c1[0][0]=n;
	c1[0][1]=m;
	c1[0][2]=t;

	int q=1,col,p;
	for(col=0;col<n;col++)
	{
		for(p=1;p<=t;p++)
		{
			if(b[p][1]==col)
			{
				c1[q][0]=b[p][1];
				c1[q][1]=b[p][0];
				c1[q][2]=b[p][2];
				q=q+1;
			}
		}
	}
	int column=c1[0][2],i;
	printf("Simple Transpose: \n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",c1[i][0],c1[i][1],c1[i][2]);
   }
}

void FastTranspose(int b[20][3],int d[20][3])
{
		int m=b[0][0];
		int n=b[0][1];
		int t=b[0][2];
		int s[n],t1[n];
	    d[0][0]=n;
        d[0][1]=m;
	    d[0][2]=t;
	    int i;
	    for(i=0;i<n;i++)
	    {
	    	s[i]=0;
		}
		for(i=1;i<=t;i++)
		{
			s[b[i][1]] = s[b[i][1]]+1;
		}
		
		t1[0]=1;
		for(i=1;i<=n;i++)
	    { 
	    	t1[i]=t1[i-1]+s[i-1];
		}
		int j;
		for(i=1;i<=t;i++)
		{
			j=b[i][1];
			d[t1[j]][0]=b[i][1];
			d[t1[j]][1]=b[i][0];
			d[t1[j]][2]=b[i][2];
			t1[j]=t1[j]+1;
		}
			int column=d[0][2];
	printf("Fast Transpose: \n");
   for(i=0;i<=column;i++)
   {
   	printf("%d\t%d\t%d\n",d[i][0],d[i][1],d[i][2]);
   }
}

int main()
{
	int r,c,choice;
	int a[10][10],b[20][3],c1[20][3],d[20][3];
	
	do
	{
	    printf("1. Accept Matrix Values\n");
	    printf("2. Display Matrix\n");
	    printf("3. Compact Form\n");
	    printf("4. Simple Transpose\n");
	    printf("5. Fast Transpose\n");
	    printf("6. EXIT\n");
	    scanf("%d", &choice);
	    switch(choice)
	    {
	        case 1:
	               printf("Enter the Number of Rows:\n");
	               scanf("%d",&r);
	               printf("Enter the Number of Columns:\n");
	               scanf("%d",&c);
	               accept(a,r,c);
	               break;
	        case 2:
	               Display(a,r,c);
	               break;
	        case 3:
	               compact(a,r,c,b);
	               break;
	        case 4:
	               Transpose(b,c1);
	               break;
	        case 5:
	               FastTranspose(b,d);
	               break;
	    }
	}
	while(choice<6);
}

