#include <stdio.h>
#include <stdlib.h>

int *stack;
int N;
int top1 = -1;
int top2;

void push1(int x) {
    if (top2 - top1 == 1) {
        printf("Stack Overflow\n");
        return;
    }
    top1++;
    stack[top1] = x;
}

void push2(int x) {
    if (top2 - top1 == 1) {
        printf("Stack Overflow\n");
        return;
    }
    top2--;
    stack[top2] = x;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = stack[top1];
    top1--;
    return x;
}

int pop2() {
    if (top2 == N) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = stack[top2];
    top2++;
    return x;
}

int main() {
    printf("Enter the size of the stack array: ");
    scanf("%d", &N);
    stack = (int *)malloc(N * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    top2 = N;

    // Example usage:
    push1(10);
    push2(20);
    printf("Popped from stack1: %d\n", pop1());
    printf("Popped from stack2: %d\n", pop2());

    free(stack);
    return 0;
}
