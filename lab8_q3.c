#include <stdio.h>
#include <stdlib.h>

#define N 10

int queue[N];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if (front == (rear + 1) % N)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        while (front != rear)
        {
            printf("%d ", queue[front]);
            front = (front + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    display();
    dequeue();
    
    enqueue(1000);
    display();
    return 0;
}