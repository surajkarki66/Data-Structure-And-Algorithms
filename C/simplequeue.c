#include<stdio.h>
#include<stdlib.h>
# define maxsize 10
typedef struct Queue queue;

struct Queue
{
    int items[maxsize];
    int rear;
    int front;
};


void initQueue(queue *q)
{
    q->rear = -1;
    q->front = -1;

}

int isEmpty(queue *q)
{
    if(q->front == -1 || q->front > q->rear)
    {
        return 1;

    }

    else 
    {
        return 0;
    }
}

int isFull(queue *q)
{
    if (q->rear == maxsize-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void enqueue(queue *q, int data)
{
    if(isFull(q))
    {
        printf("\nData is overflow");
        exit(0)
       
    }

    else if(q->rear == -1 && q->front == -1)
    {
        q->rear = 0;
        q->front = 0;
    }

    else 
    {
        q->rear++;
       
       
    }
    q->items[q->rear] = data;
       
}

int dequeue(queue *q)
{
    int data;

    if(isEmpty(q))
    {
        printf("\nData is underflow");
        exit(0)
       
    }

    else 
    {
        data = q->items[q->front];
        q->front++;
        return data;
    }
}

void traverse(queue *q)
{
    int i,data;
    if (isEmpty(q))
    {
        printf("\nData is underflow");
        exit(1);

    }

    else 
    {
        for (i=q->front;i <= q->rear;i++)
        {
            data = q->items[i];
            printf("\n%d",data);
        }
    }
}


int main()
{
    struct Queue q, *Q;
    int choice;
    int data;
    Q = &q;
    initQueue(Q);
    do
    {
       
        printf("\nPress 1 for Enqueue:");
        printf("\nPress 2 for Dequeue");
        printf("\nPress 3 for Traverse of Queue:");
        printf("\nPress 4 for exit:");
        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                
                printf("\nEnter the data:");
                scanf("%d", &data);
                enqueue(Q, data);
                printf("\n%d is successfully added.");
                break;

            case 2:
                dequeue(Q);
                printf("\nData is successfully deleted.");
                break;

            case 3:
                printf("\nThe elements of the Queue are");
                traverse(Q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice");
                break;

            



        

      


        }

        

    }while(choice=4);

    return 0;
}