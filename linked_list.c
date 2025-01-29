#include <stdio.h>
#include <stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };

void printlist( struct node *head){
    struct node *curr = head;
    while(curr !=NULL){
        printf("|%d|",curr->data);
        curr = curr->next;
    }
}

int main()
{

    struct node *head, *nnode, *temp;
    head = 0;
    int option = 1;
    while (option != 0)
    {
        nnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", &nnode->data);
        nnode->next = 0;
        if (head == 0)
        {
            head = nnode;
            temp = head;
        }
        else
        {
            temp->next = nnode;
            temp = nnode;
        }
        printf("Do you want to continue (for yes = 1, no = 0):");
        scanf("%d", &option);
    }
    printlist(head);
    return 0;
}