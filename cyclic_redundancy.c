#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10],b[10],d[5],i,j,r[5],c,flag;
    printf("\t-----------------Transmitter----------------- \n");
    printf("Enter 4 bit data word:\n");
    int p=3;
    for(i=0; i<4; i++)
    {
        printf("\n\ta%d: ",p--);
        scanf("%d",&a[i]);
    }
    
    printf("Enter 4 generator bits:\n");
    p=3;
    for(i=0;i<4;i++)
    {
        printf("\n\td%d: ",p--);
        scanf("%d",&d[i]);
    }
    
    for(i=4;i<7;i++)
    a[i]=0;
    
    for(c=0;c<4;c++)
    r[c]=a[c];
    
    while(c<8)
    {
        while(r[0]==0)
        {
            if(c==7)
            break;
            for(i=0;i<3;i++)
                r[i]=r[i+1];
            r[3]=a[c++];
        }
        if(r[0]==0)
        break;
        for(j=0;j<4;j++)
        r[j]=r[j]^d[j];
    }

    printf("\nCRC bits are: ");
    for(i=1;i<4;i++)
    printf(" %d",r[i]);
    
    j=1;
    for(i=4;i<7;i++)
    {
        a[i]=r[j];
        j++;
    }
    
    printf("\n Transmitted data: ");
    for(i=0;i<7;i++)
    printf(" %d",a[i]);
    
    printf("\n\t-----------------Receiver----------------- \n");
    
    p=3;
    for(i=0; i<4; i++)
    {
        printf("\n\tb%d: ",p--);
        scanf("%d",&b[i]);
    }
    p=2;
    for(i=4; i<7; i++)
    {
        printf("\n\tq%d: ",p--);
        scanf("%d",&b[i]);
    }
    
    for(c=0;c<4;c++)
    r[c]=b[c];
    
    while(c<8)
    {
        while(r[0]==0)
        {
            if(c==7)
            break;
            for(i=0;i<3;i++)
                r[i]=r[i+1];
            r[3]=b[c++];
        }
        if(r[0]==0)
        break;
        for(j=0;j<4;j++)
        r[j]=r[j]^d[j];
    }
    
    printf("\nSyndrome bits are: ");
    for(i=1;i<4;i++)
    printf(" %d",r[i]);
    
    for(i=0;i<4;i++)
    if(r[i]==0)
    flag++;
    if(flag==4)
    printf("\nThe received codeword is correct.");
    else
    printf("\nThe received codeword is INCORRECT.");

    return(0);
}



