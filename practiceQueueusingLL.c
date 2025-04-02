#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *temp = NULL, *nnode;

void enqueue(int data)
{
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    if (front == NULL && rear == NULL)
    {
        front = rear = nnode;
        nnode->next = NULL;
    }
    else
    {
        rear->next = nnode;
        rear = nnode;
        rear->next = NULL;
    }
}

void dequeue()
{
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    if(front == rear){
        front = rear =  NULL;
        free(temp);
        return;
    }
    front = temp->next;
    free(temp);
}

void printqueue(struct node *front)
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
// front = rear = temp = NULL;
// int option = 1;
// int data;
// // creation of queue
// while (option)
// {
//     nnode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter data:\n");
//     scanf("%d", &nnode->data);
//     if (front == NULL)
//     {
//         front = rear = nnode;
//         front->next == NULL;
//     }
//     else
//     {
//         rear->next = nnode;
//         rear = nnode;
//         rear->next == NULL;
//     }
//     printf("Do you want to continue:\n");
//     printf("enter 1 for yes\n");
//     printf("enter 0 for no\n");
//     scanf("%d", &option);
// }

int main()
{
    
    return 0;
}