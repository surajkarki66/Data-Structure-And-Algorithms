#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int info;
    struct Node *next;
};

typedef struct Node node;
node *top = NULL;

void push(int data)
{
    node *s;
    s = (node*)malloc(sizeof(node));
    s->info = data;
    if (top == NULL)
    {
        s->next = NULL;
        top = s;
    }
    else {
        s->next = top;
        top = s;
    }
}

void pop()
{
    node *ptr;
    ptr = top;
    if (ptr == NULL)
    {
        printf("\nUnderflow");
        exit(1);
    }
    top = top->next;
    printf("\n%d is deleted", ptr->info);
    free(ptr);
}


void PrintStack()
{
    node *ptr;
    ptr = top;
    
    while (ptr->next != NULL)
    {
        printf("\n%d", ptr->info);
        ptr = ptr->next;

    }
    
}

int main()
{
    int choice,data;
   
    do 
    {
        printf("\nPress 1 push:");
        printf("\nPress 2 to pop:");
        printf("\nPress 3 to display:");
        printf("\nPress 4 to exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data:");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;
        case 3:
            PrintStack();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice");
            break;
        }

    }while (choice != 4);
    return 0;
}
