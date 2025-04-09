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
    else if (rear == N - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        queue[++rear] = data;
    }
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Queue is empty");
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
            front++;
        }
    }
}
int main()
{
    return 0;
}