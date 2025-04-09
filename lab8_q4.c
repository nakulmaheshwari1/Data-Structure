#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    char name[50];
    int age;
    int token;
    int waitingNo;
    struct node *next;
};
struct node *front = NULL, *rear = NULL, *nnode, *temp;
int i = 0;
void enqueue(char name[], int age)
{
    nnode = (struct node *)malloc(sizeof(struct node));
    strcpy(nnode->name, name);
    nnode->age = age;
    nnode->waitingNo = i;
    nnode->token = i++;

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
void dequeue(){
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
    temp = temp->next;
    while(temp!= NULL){
        temp->waitingNo--;
        temp->token--;
        temp = temp->next;
    }
    temp = front ;
    front = temp->next;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Queue Status\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Token: %d\n", temp->token);
        printf("Waiting Number: %d\n", temp->waitingNo);
        temp = temp->next;
    }
}
int main()
{
    
    return 0;
}