#include<stdio.h>
int main()
{
    int c, r, i1, i2, p[10][10], q[10][10], add[10][10], sub[10][10];
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter the %d elements of the first matrix: ", r*c);
    for(i1 = 0; i1 < r; i1++)
        for(i2 = 0; i2 < c; i2++)
            scanf("%d", &p[i1][i2]);
    printf("Enter the %d elements of the second matrix: ", r*c);
    for(i1 = 0; i1 <r; i1++)
        for(i2 = 0; i2 < c; i2++)
            scanf("%d", &q[i1][i2]);
    for(i1 = 0; i1 < r; i1++)
        for(i2 = 0; i2 < c; i2++)
            add[i1][i2] = p[i1][i2] + q[i1][i2];
    printf("The addition of the two entered matrices is: \n");
    for(i1 = 0; i1 < r; i1++)
    {
        for(i2 = 0; i2 < c; i2++)
                printf("%d\t", add[i1][i2]);
     printf("\n"); }
    for(i1 = 0; i1 < r; i1++)
        for(i2 = 0; i2 < c; i2++)
            sub[i1][i2] = p[i1][i2] - q[i1][i2];
    printf("\n The subtraction of the two entered matrices is: \n");
    for(i1 = 0; i1 < r; i1++)
    {
        for(i2 = 0; i2 < c; i2++)
                printf("%d\t", sub[i1][i2]);
    printf("\n"); }
    return 0;
}
