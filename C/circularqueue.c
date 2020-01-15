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
    cqueue c,*q;
    q = &c;
    initqueue(q);
    enqueue(q, 10);
     enqueue(q, 10);
      enqueue(q, 10);
       enqueue(q, 10);
       dequeue(q);
       traverse(q);
       return 0;




}