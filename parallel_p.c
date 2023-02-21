#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>
void mergesort(int x[],int lb,int ub);
void merge(int x[],int lb1,int ub1,int ub2);
void generate_list(int * x, int n) {
   int i,j,t;
   for (i = 0; i < n; i++)
     x[i] = i;
   for (i = 0; i < n; i++) {
     j = rand() % n;
     t = x[i];
     x[i] = x[j];
     x[j] = t;
   }
}

int count=0;
#define MAX_SIZE 100000
void main()
{
	clock_t t;
	int x[MAX_SIZE];
	int n,i;
	
	printf("Enter the no of elements:\n");
	scanf("%d",&n);
	generate_list(x, n);
	t=clock();
	mergesort(x,0,n-1);
	t=clock()-t;
	printf("\n\nThe sorted list is\n");
	for(i=0;i < n;i++)
		printf("%d ",x[i]);
	printf("\nTime: %Lf\n",(long double)t);
	getch();
}

void mergesort(int x[],int lb,int ub)
{
    int mid;
    if(lb < ub)
	{
		count++;
		mid=(lb+ub)/2;
		mergesort(x,lb,mid);
		mergesort(x,mid+1,ub);
		merge(x,lb,mid,ub);
	}
}

void merge(int x[],int lb1,int ub1,int ub2)
{
	int temp[MAX_SIZE],i,j,k;
	i=lb1;
	j=ub1+1;
	k=0;
	while(i <= ub1&&j <= ub2)
	{
		count++;
		if(x[i] < x[j])
		{          
			count++;
			temp[k++]=x[i++];
		}
		else
		{
			count++;
			temp[k++]=x[j++];
		}
	}
	while(i <= ub1)
	{
		count++;
		temp[k++]=x[i++];
	}
	while(j <= ub2)
	{
		count++;
		temp[k++]=x[j++];
	}
	for(i=lb1,j=0;i <= ub2;i++,j++)
	{
		count++;
		x[i]=temp[j];
	}
}
