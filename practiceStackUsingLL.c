#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL, *temp = NULL;
struct node *nnode;
void push(int data)
{
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = top;
    top = nnode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Nothing to pop\n");
        return;
    }
    temp = top;
    printf("popped element is %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    printf("%d is top element\n",top->data);
}


int main()
{
    
    return 0;
}