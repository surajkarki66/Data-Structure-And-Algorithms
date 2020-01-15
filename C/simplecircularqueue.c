#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

struct CircularQueue
{
    int items[maxsize];
    int front;
    int rear;
};

typedef struct CircularQueue cqueue;

void initqueue(cqueue *q)
{
    q->rear = maxsize-1;
    q->front = maxsize-1;
}

int isEmpty(cqueue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(cqueue *q)
{
    if (q->front==(q->rear+1)%maxsize)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

}

void enqueue(cqueue *q, int data)
{
    if(isFull(q))
    {
        printf("\nData is overflow");
        exit(1);
    }

    else
    {
        q->rear = (q->rear+1)%maxsize;
        q->items[q->rear] = data;
       
      
    }
   

}

int dequeue(cqueue *q)
{
    int data;
    if (isEmpty(q))
    {
        printf("\nData is underflow");
        exit(1);
    }
    else 
    {
        q->front = (q->front+1)%maxsize;
        data = q->items[q->front];
        return data;

    }

}

void traverse(cqueue *q)
{
    int data, i;
    if(isEmpty(q))
    {
        printf("\nData is underflow");
        exit(1);
    }
    else 
    {
        for(i=(q->front+1)%maxsize;i!=q->rear;i=(i+1)%maxsize)
        {
            data = q->items[i];
            printf("\n%d", data);
        }
    }
}

int main()
{
    cqueue q, *Q;
    int choice;
    int data;
    Q = &q;
    initqueue(Q);
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