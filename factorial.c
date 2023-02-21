#include<stdio.h>

long int multi(int n)
{
if(n>=1)
    return n*multi(n-1);
else
    return 1;
}

int main()
{
    int n;
    printf("Enter positive number:");
    scanf("%d", &n);
    printf("Factorial of %d = %ld", n, multi(n));
    return 0;
}
