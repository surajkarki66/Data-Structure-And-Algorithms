#include<stdio.h>
#include<stdlib.h>
# define maxsize 10
typedef struct Queue queue;

struct Queue
{
    int items[maxsize];
    int rear,front;
};


void initQueue(queue *q)
{
    q->rear = -1;
    q->front = -1;

}

int isEmpty(queue *q)
{
    if(q->front==-1)
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
        exit(1);
    }

    else if(q->rear==-1 && q->front==-1)
    {
        q->rear = 0;
        q->front = 0;
    }

    else 
    {
        q->items[q->rear] = data;
        q->rear++;
    }
}

int dequeue(queue *q)
{
    int data;

    if(isEmpty(q))
    {
        printf("\nData is underflow");
        exit(1);
    }

    else 
    {
        data = q->items[q->front];
        for (int i=q->front;i<q->rear;i++)
        {
            q->items[i] = q->items[i+1];
          
        }
        q->rear--;
            
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
    Q = &q;
    initQueue(Q);
    int i=1;
    while (i<10)
    {
       enqueue(&q,10);
       i += 1;
    }
    

    
   
    traverse(Q);
    return 0;
}