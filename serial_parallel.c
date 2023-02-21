#include<stdio.h>
#include<pthread.h>
#include<omp.h>
#include<stdlib.h>
#include<sys/time.h>


void serial(int a[], int b[], int d[], int MAX){
    
		int i;
	for(i=0;i<MAX;i++)
	{
		d[i] = a[i] + b[i];
	}
	
//	 printf("\nAddition of arrays : ");
//	for(i=0;i<MAX;i++)
//	{
//		printf(" %d ",d[i]);
//	}

}


void parallel(int a[], int b[], int c[], int MAX){
	
		int i;
	#pragma omp parallel
	for(i=0;i<MAX;i++)
	{
		c[i] = a[i] + b[i];
	}

//	 printf("\nAddition of arrays : ");
//	for(i=0;i<MAX;i++)
//	{
//		printf(" %d ",c[i]);
//	}
	

}

int main()
{
	
	int i;
    //int num_cores= omp_get_num_procs();
	//printf("Cores : %d",num_cores);
	//omp_set_num_threads(num_cores);
	int MAX;
    
    scanf("%d", &MAX);
    printf("\n value of MAX : %d",MAX);
    int a[MAX], b[MAX], c[MAX], d[MAX];
	for(i=0;i<MAX;i++)
	{
		a[i] = rand()%MAX;
	}

	for(i=0;i<MAX;i++)
	{
		b[i] = rand()%MAX;
	}
//	printf("\nfirst array : \n");
//	for(i=0;i<MAX;i++)
//	{
//		printf(" %d ",a[i]);
//	}
//	printf("\n");
//	printf("\nsecond array : \n");
//	for(i=0;i<MAX;i++)
//	{
//		printf(" %d ",b[i]);
//	}
//	printf("\n");
	
	printf("\nSerial Execution\n");
	clock_t t;
	t=clock();
	serial(a, b, d, MAX);
	t=clock()-t;
	printf("\nSerial ");
	printf("Time: %Lf\n",(long double)t);
	printf("\nParallel execution\n");
	t=clock();
    parallel(a, b, c, MAX);
    t=clock()-t;
	printf("\nParallel ");
	printf("Time: %Lf\n",(long double)t);
	
	 return 0;
}

