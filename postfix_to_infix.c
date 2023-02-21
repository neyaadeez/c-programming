#include <stdio.h>
#define MAXSIZE 20      
char stack[MAXSIZE];     
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



void postfix_to_infix(char expression[])
{
      int l,i;
      char element, operator;
      
      l=strlen(expression);
      
      for(i=0;i<MAX;i++)
      {
            stack[i]=0;
      }
      
      for(i=1;i<l;i++)
      {
            if(expression[i] == '-' || expression[i] == '/' || expression[i] == '*'|| expression[i] == '+')
            {
                  element = pop();
                  operator = expression[i];
                  printf(" %c %c", operator, element);
            }
            else
            {
                  push(expression[i]);
            }
      }
      printf("%c", expression[top--]);
}
 
int main()
{
      char postfix_expression[50];
      printf("\nEnter Postfix Expression:\t");
      scanf("%s", postfix_expression);
      postfix_to_infix(postfix_expression);
      printf("\n");
      return 0;
}
