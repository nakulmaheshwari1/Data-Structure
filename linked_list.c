#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("|%d|", curr->data);
        curr = curr->next;
    }
}

void insert_at_Beginning(struct node *head, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = head;
    head = new_node;
}

void insert_at_specificPosition(struct node *head, int data, int position)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int i;
    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_end(struct node *head, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    temp = new_node;
    temp->data = data;
    temp->next = 0;
}

int main()
{

    struct node *head, *nnode, *temp;
    head = 0;
    int option = 1;
    char choice;
    int pos, data;
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
    printf("\n");
    printf("Do you want to enter the data\n");
    printf("Y for yes \nN for no");
    getchar();           // when we shift scanf from int to char input data type the new line character because of enter key we press remain in the input buffer nd if we not use getchar the new line will read by scanf and cause error 
    scanf("%c", &choice);
    if (choice == 'Y')
    {
        printf("Enter position where you want to enter data:");
    }
    return 0;
}