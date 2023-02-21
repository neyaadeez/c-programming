#include <stdio.h>


void transpose(int b1[][3],int b2[][3]);
void fast(int B[10][10],int C[10][10]);
void accept(int A[20][20],int m, int n)
{
    int i,j;
    printf("\nenter elements of matrix A row by row\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("\n%d",&A[i][j]);
        }
        
    }
}

void display(int A[20][20], int m, int n)
{
    int i,j;
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

void compact(int A[20][20],int m,int n,int B[20][20])
{
    int i,j,q=1;
    B[0][0]=m;
    B[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                B[q][0]=i;
                B[q][1]=j;
                B[q][2]=A[i][j];
                q++;
            }
        }
    }
    B[0][2] = q-1;
}


void displaycom(int A[20][20], int m, int n)
{
    int i,j;
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


int main()
{
    int m,n,l;
    printf("\nenter number of rows: ");
    scanf("\n%d",&m);
    printf("\nenter number of columns: ");
    scanf("\n%d",&n);
    int mat1[20][20];
    int com1[20][20];
    accept(mat1,m,n);
    display(mat1,m,n);
    
    printf("\nCompact form:");
    compact(mat1,m,n,com1);
    l=com1[0][2]+1;
    displaycom(com1,l,3);
    

    
    return 0;
}




void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	
	k=1;
	n=b1[0][2];
	
	for(i=0;i<b1[0][1];i++)
		for(j=1;j<=n;j++)
			if(i==b1[j][1])
			{
				b2[k][0]=i;
				b2[k][1]=b1[j][0];
				b2[k][2]=b1[j][2];
				k++;
			}
}



void fast(int B[10][10],int C[10][10])
{
     int i,j,m,n,pos[3]={0,0,0},count[3]={0,0,0};
     for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        count[m]++;
    }
    pos[0] = 1;
    for (i=1;i<B[0][1];i++)
    {
        pos[i] = pos [i-1] + count[i-1];
    }
    for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        n= pos[m];
        pos[m]++;
        C[n][0] = B[i][1];
        C[n][1] = B[i][0];
        C[n][2] = B[i][2];
    }
    C[0][0] = B[0][0];
    C[0][1] = B[0][1];
    C[0][2] = B[0][2];
}




