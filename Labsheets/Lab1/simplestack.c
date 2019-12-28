#include<stdio.h>
#include<stdlib.h>
#define maxsize 10;
typedef struct Stack stack;

struct Stack
{
    int item[10];
    int top;

};

void CreateEmptyStack(stack *s)
{
    s->top = -1;
}



int isFull(stack *s)
{
    if(s->top==9)
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


int main() 
{
    int element, choice,flag,top_element,pop_element;
    stack st;
    stack *s;
    s = &st;
    CreateEmptyStack(s);

    printf("\n Enter your choice:");
    printf("\n\n Press1: to push the elements:");
    printf("\n\nPress2: to display the elements:");
    printf("\n\nPress3: to pop the elements:");
    printf("\n\nPress4: To check the top elements:");
    printf("\n\n Press5 Exit:");
    printf("\n\nEnter your choice:");
    printf("%d",&choice);
    switch(choice) {
        case 1:
            printf("\nEnter the number:");
            scanf("%d",&element);
            push(s,element);
            break;

        case 2:
            printf("\nElements in the stack:");
            PrintStack(s);
            break;

        case 3:
            pop_element = pop(s);
            printf("\n%d is poped from the stack.",pop_element);
            break;

        case 4:
            top_element = top(s);
            printf("\n%d is top element.",top_element);
            break;

        default:
            printf("\nInvalid data.");
            break;

    }



    return 0;
}


   /*
    for(int i=0;i<10;i++)
    {
         printf("\nEnter the element:");
         scanf("%d",&element);
         push(s,element);
    }
   
    PrintStack(s);
    printf("\nThe top element is %d",top(s));
    pop(s);
    PrintStack(s);
    */
  
        
