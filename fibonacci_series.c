#include<stdio.h>
int main()
{
    int n, a=0, b=1, c;
    printf("Enter the positive integer: ");
    scanf("%d", &n);
    printf("\n Fibonacci series is: ");
    
        while (a <= n)
    {
	    printf("%d, ", a);
	    c = a + b;
	    a = b;
    	b = c;
    }
    
   return 0;
}                       
