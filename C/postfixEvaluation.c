#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
#define maxsize 10
typedef struct Stack stack;

struct Stack
{
    int item[maxsize];
    int top;

};

void CreateEmptyStack(stack *s)
{
    s->top = -1;
}



int isFull(stack *s)
{
    if(s->top==maxsize-1)
    {
        return 1;
    }
    
    else {
        return 0;
    }
}

int isEmpty(stack *s) 
{
    if(s->top ==-1)
    {
        return 1;
    }
    else {
        return 0;
    }
}

void push(stack *s, int data)
{

    if(isFull(s))
    {
        printf("\nData is overflow");
        exit(1);
    }
    else 
    {
        (s->top)++;
        s->item[s->top] = data;

    }
}

int pop(stack *s) 
{
    int temp =0;
    if(isEmpty(s))
    {
        printf("\nThe data is underflow");
        exit(1);
    }
    else {
        temp = s->item[s->top];
        (s->top)--;
    }
    return temp;
}

int top(stack *s)
{
    int temp =0;
    if(isEmpty(s))
    {
        printf("\nThe data is underflow");
        exit(1);
    }
    else {
        temp = s->item[s->top];
        
    }
    return temp;
}

void PrintStack(stack *s)
{
    int i;
    for(i=0;i<=s->top;i++)
    {
        printf("\n%d",s->item[i]);
    }
}


int evaluatePostfix(char exp[])
{
    int op1,op2,r,i=0,d;
    stack s;
    CreateEmptyStack(&s);
    while(exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(&s,(exp[i] - '0'));
        }

        else if(isalpha(exp[i]))
        {
            printf("\nEnter the value of %c",exp[i]);
            scanf("%c", &d);
            push(&s,d);

        }

        else 
        { 
            op1 = pop(&s); //top element
            op2 = pop(&s);  // next top element
            switch(exp[i])
            {
                case '+':
                     r = op2 + op1;
                     break;

                case '-':
                    r = op2-op1;
                    break;

                case '*':
                    r = op2*op1;

                case '/':
                    r = op2/op1;

                case '^':
                    r = op2 ^ op1;

                default:
                    printf("\nError");
                    break;
                
            }

                push(&s,r);
        }
        i++;
    }
    return pop(&s);

}


int main()
{

    int result;
    char exp[100];
    printf("\nEnter the postfix expression");
    scanf("%s",exp);
    result = evaluatePostfix(exp);
    printf("\n%d",result);
    return 0;
}



  
        
