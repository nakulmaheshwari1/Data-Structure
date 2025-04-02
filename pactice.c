#include <stdio.h>
#include <stdlib.h>
#define N 10

int st1[N];
int st2[N];
int top1 = -1, top2 = -1;

void push(int x)
{
    if (top1 == -1)
    {
        top1++;
        st1[top1] = x;
    }
    else if (top1 == N - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        while (top1 != -1)
        {
            top2++;
            st2[top2] = st1[top1];
            top1--;
        }
        top1++;
        st1[top1] = x;
        int i = -1;
        while (i != top2)
        {
            i++, top1++;
            st1[top1] = st2[i];
        }
    }
}

void pop()
{
    if (top1 == -1) {
        printf("Queue is empty, cannot pop\n");
        return;
    }
    printf("popped element: %d\n", st1[top1]);
    top1--;
}

void display()
{
    if (top1 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", st1[i]);
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    push(40);
    display();
    return 0;
}