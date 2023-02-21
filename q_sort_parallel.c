#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

long long int n = 500;             //Change the values of n 
#define NUM_THREAD 8;

int Partition(int l, int h, int arr[])
{
    int pivot = arr[h];
    int i = l - 1;
    int temp;

    for(int j = l; j <= h-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = temp;

    return (i+1);
}

void Q_Sort_serial(int l, int h, int arr[])
{
    if(l < h)
    {
        int p = Partition(l ,h, arr);

        Q_Sort_serial(l, p-1, arr);
        Q_Sort_serial(p+1, h, arr);
    }
}

void Q_Sort_parallel(int l, int h, int arr[])
{
    if (l < h)
    {
        int p = Partition(l, h, arr);

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                Q_Sort_parallel(l, p - 1, arr);
            }

            #pragma omp section
            {
                Q_Sort_parallel(p + 1, h, arr);
            }
        }
    }
}

int main()
{
    long long int i;

    int *arr, *arr1;

    arr = (int *)malloc(sizeof(int) * n);
    arr1 = (int *)malloc(sizeof(int) * n);

    printf("\nFor n = %lld\n", n);
    for(i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
        arr1[i] = arr[i]; 
    }

    //int total_threads = NUM_THREAD;
    //omp_set_num_threads(total_threads);


    clock_t t;
	t=clock();
    Q_Sort_serial(0, n - 1, arr);
	t=clock()-t;
	printf("\nSerial ");
	printf("Time: %Lf\n",(long double)t);

    t=clock();
    Q_Sort_parallel(0, n - 1, arr1);
    t=clock()-t;
	printf("\nParallel ");
	printf("Time: %Lf\n",(long double)t);

    return 0;
}
