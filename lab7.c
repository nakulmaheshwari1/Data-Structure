#include <stdio.h>
#include <stdlib.h>

#define N 10

int stack[N];
int top = -1;
void push(int data)
{
    if(top == N-1){
        printf("Stack is full\n");
    }else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty\n");
    }else{
        
    }
}

int main()
{

    return 0;
}