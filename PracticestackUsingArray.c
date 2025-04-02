#include <stdio.h>
#include <stdlib.h>

#define N 10
int stack[N];
int top = -1;

void push(int data)
{
    if (top == N - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = data;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("NOthing to pop ,stack is empty");
    }
    else
    {
        printf("%d is popped out", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d is top element", stack[top]);
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty!\n");
    }
}

void display(){
    if(top == -1){
        printf("satck is empty");
    }else{
        int i;
        for(i=top;i>=0;i--){
            printf("%d->",stack[i]);
        }
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    
    pop();
    display();

    return 0;
}