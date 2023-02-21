#include<stdio.h>
#include<pthread.h>

int A1(int a[3])
{
    a[2] = a[1] + a[0];  
    printf("Result from thread 1 is %d\n",a[2]);
}

int A2(int b[3])
{
    b[2] = b[1] + b[0];  
    printf("Result from thread 2 is %d\n",b[2]);
}

int main()
{ 	
    int arr[4],a[3],b[3],i,final=0;
    pthread_t thread1,thread2;
    printf("Enter 4  numbers\n");
    for(i=0;i<4;i++)		
        scanf("%d",&arr[i]);
    a[0]=arr[0];
    a[1]=arr[1];	
    b[0]=arr[2];
    b[1]=arr[3];
    pthread_create(&thread1,NULL,(void*)A1,a);
    pthread_create(&thread2,NULL,(void*)A2,b);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    final=a[2]+b[2];
    printf("Result = %d\n",final);
    
    return 0;
}

