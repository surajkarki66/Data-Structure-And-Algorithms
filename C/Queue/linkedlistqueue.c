#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node node;

node *front = NULL;
node *rear = NULL;

void enqueue(int data) 
{
    node *p;
    p = (node*) malloc(sizeof(node));
    p->info = data;
    if (front == NULL)
    {
        front = rear= p;
        p->next = NULL;
    }

    else {
       rear->next = p;
       rear = p;
       p->next = NULL;

    }
}

void dequeue()
{
    node *ptr;
    if (front == NULL)
    {
        printf("\nUnderflow");
        exit(0);
    }
    else {
        ptr = front;
        front = front->next;
        printf("\nThe deleted data is %d", ptr->info);
        free(ptr);
        
       

    }

}

void traverse()
{
    node *ptr;
    int i;
    ptr = front;
    while (ptr!=NULL)
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
        printf("\nPress 1 Enqueue:");
        printf("\nPress 2 Dequeue:");
        printf("\nPress 3 to display:");
        printf("\nPress 4 to exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data:");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;
        case 3:
            traverse();
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
