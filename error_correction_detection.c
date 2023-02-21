#include<stdio.h>
#include<stdlib.h>

void invert(int x[],int n)
{
    if(x[n]==0)
        x[n]=1;
    else
        x[n]=0;
}

void display(int x[],int y[])
{
    printf("Corrected Code word: \n");
        for(int i=3;i>=0;i--)
            printf("\t%d",x[i]);
        for(int i=2;i>=0;i--)
            printf("\t%d",y[i]);
}

void data(int x[])
{
    printf("\nDecoded Data Word: \n");
        for(int i=3;i>=0;i--)
            printf("\t%d",x[i]);
}

int main()
{
    int a[4],b[4],r[3],s[3],i,q[3],flag=0;
    printf("\t-----------------Transmitter----------------- \n");
    printf("enter 4 bit data word:\n");
    for(i=3;i>=0;i--)
    {
        printf("\n\ta%d: ",i);
        scanf("%d",&a[i]);
    }
    
    r[0]=(a[2]+a[1]+a[0])%2;
    r[1]=(a[3]+a[2]+a[1])%2;
    r[2]=(a[1]+a[0]+a[3])%2;

    printf("\nTransmitted Code word: \n");
    for(i=3;i>=0;i--)
        printf("%d\t",a[i]);
    for(i=2;i>=0;i--)
        printf("%d\t",r[i]);
    
    printf("\n\n\n\t-----------------Receiver----------------- \n");
    printf("\nEnter the recieved Code word: \n");
    
    for(i=3;i>=0;i--)
    {
        printf("\n\tb%d: ",i);
        scanf("%d",&b[i]);
    }
    for(i=2;i>=0;i--)
    {
        printf("\n\tq%d: ",i);
        scanf("%d",&q[i]);
    }
    
    s[0]= (b[2]+b[1]+b[0]+q[0])%2;
    s[1]= (b[3]+b[2]+b[1]+q[1])%2;
    s[2]= (b[1]+b[0]+b[3]+q[2])%2;
    
    printf("\nSyndrome: \n");
    for(i=2; i>=0;i--)
        printf("\t%d",s[i]);
    
        if(a[3]!=b[3])
            flag++;
        if(a[2]!=b[2])
            flag++;
        if(a[1]!=b[1])
            flag++;
        if(a[0]!=b[0])
            flag++;
        if(r[2]!=q[2])
            flag++;
        if(r[1]!=q[1])
            flag++;
        if(r[0]!=q[0])
            flag++;
    
        if(flag<1)
        {
        if((s[2]==0) && (s[1]==0) && (s[0]==0))
        {
            printf("\nNO ERROR\n");
            data(b);
            exit(0);
        }
        if((s[2]==1) && (s[1]==0) && (s[0]==1))
        {
            printf("\nError in position 'b0'\n");
            invert(b,0);
        }
                
        if((s[2]==1) && (s[1]==1) && (s[0]==1))
        {
            printf("\nError in position 'b1'\n");
            invert(b,1);
        }
        if((s[2]==0) && (s[1]==1) && (s[0]==1))
        {
            printf("\nError in position 'b2'\n");
            invert(b,2);
        }
        if((s[2]==1) && (s[1]==1) && (s[0]==0))
        {
            printf("\nError in position 'b3'\n");
            invert(b,3);
        }
        if((s[2]==0) && (s[1]==0) && (s[0]==1))
        {
            printf("\nError in position 'q0'\n");
            invert(q,0);
        }
        if((s[2]==0) && (s[1]==1) && (s[0]==0))
        {
            printf("\nError in position 'q1'\n");
            invert(q,1);
        }
        if((s[2]==1) && (s[1]==0) && (s[0]==0))
        {
            printf("\nError in position 'q2'\n");
            invert(q,2);
        }
        }
    
    if(flag>1)
    {
        printf("\n!!!!There are more than one errors in recieved code word!!!!\n");
    }
    else
    {
        display(b,q);
        data(b);
    }
    
    return(0);
}

