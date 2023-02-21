#include <stdio.h>
#include <string.h>
#define MAXSIZE 20      
char str[MAXSIZE],stack[MAXSIZE];     
int top = -1;            

int isFull()
{

   if(top == MAXSIZE-1)
      return 1;
   else
      return 0;
}

void push(char data)
{

   if(!isFull())
   {
      top = top + 1;   
      stack[top] = data;
   }
   else
      printf("Stack is full.\n");
}


int isEmpty()
{

   if(top == -1)
      return 1;
   else
      return 0;
}


char pop()
{
   char data;
	
   if(!isEmpty())
   {
      data = stack[top];
      top = top - 1;   
      return data;
   }
   else
      printf("Stack is empty.\n");
}


int icp(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 4;
	if (ch == '(')
		return 5;
	else
	    return 0;
}

int isp(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	else
	    return 0;
}


void postf(char expr[20])
{
	char postfix[20];
	int k=0, i=0;
	char ch;
	ch=expr[i];
	while(expr[i]!='\0')
	{
		if(ch=='(')
		{
			push('(');
		}
		else
		if(ch==')')
		{
			while((ch=pop())!='(')
			{
				postfix[k]=ch;
				k++;
			}
		}
		else
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		{
			while(top>=0 && isp(stack[top])>=icp(ch))
			{
				postfix[k]=pop();
				k++;
			}
			push(ch);
		}
		else
		{
			postfix[k]=ch;
			k++;
		}
		i++;
		ch=expr[i];
	}
	while(top>=0)
	{
		postfix[k]=pop();
		k++;
	}
	printf("\nPostfix expression is: %s", postfix);
}

void posinfix(char expression[])
{
      int count, length;
      char element, operator;
      length = strlen(expression);
      for(count = 0; count < MAXSIZE; count++)
      {
            stack[count] = 0;
      }
      printf("\nInfix Expression:\t");
      printf("%c", expression[0]);
      for(count = 1; count < length; count++)
      {
            if(expression[count] == '-' || expression[count] == '/' || expression[count] == '*'|| expression[count] == '+')
            {
                  element = pop();
                  operator = expression[count];
                  printf(" %c %c", operator, element);
            }
            else
            {
                  push(expression[count]);
            }
      }
      printf("%c", expression[top--]);
}

int main()
{
    int choice;
    char expr[20],expr1[20];
    do
    {
        printf("\n1. Convert Infix to Postfix\n");
        printf("2. Convert Postfix to Infix\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter the infix expression: ");
				scanf("%s", expr);
				postf(expr);
				break;
			case 2:
			    printf("\nEnter Postfix Expression:\t");
                scanf("%s", expr1);
                posinfix(expr1);
                break;
        }
    }while(choice!=3);
    return 0;
}



