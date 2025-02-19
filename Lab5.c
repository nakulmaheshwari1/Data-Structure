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
void swapSmallestToFirst(struct node *head)
{
    struct node *temp = head;
    struct node *addSmallest = head;
    int smallest = head->data;
    while (temp != NULL)
    {
        if (temp->data < smallest)
        {
            smallest = temp->data;
            addSmallest = temp;
        }
        temp = temp->next;
    }
    
    addSmallest->data = head->data;
    head->data = smallest;
}
void swapLargestTolast(struct node *head){
    struct node *temp = head;
    struct node* tail = NULL;
    struct node *addlargest = head;
    int largest = head->data;
    while(temp != NULL){
        if(largest < temp->data){
            largest = temp->data;
            addlargest = temp;
        }
          tail = temp;
          temp = temp->next;      
    }
    addlargest->data = tail->data;
    tail->data = largest;
}

void splittingLLEvenOdd(struct node* head){
    struct node *headOdd, *headEven, *prevOdd, *prevEven, *temp;
    headEven = NULL;
    headOdd  = NULL;
    prevEven = NULL;
    prevOdd = NULL;
    temp = head;
    while (temp != NULL){
        if(temp->data % 2 != 0){
            if(headOdd == NULL){
                headOdd = temp;
                prevOdd = temp;
            }else{
                prevOdd->next = temp;
                prevOdd = temp;
            }
        }else{
            if(headEven == NULL){
                headEven = temp;
                prevEven = temp;
            }else{
                prevEven->next = temp;
                prevEven = temp;
            }
        }
        temp = temp->next;
    }
    prevOdd->next = NULL;
    prevEven->next = NULL;
    printf("Even list:\n");
    printlist(headEven);
    printf("\n");
    printf("odd list:\n");
    printlist(headOdd);
    printf("\n");
}
void lengthofLL(struct node* head){
    struct node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    printf("Length of linked list = %d",length);
}
void lastThirdNode(struct node* head){
    
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("List has fewer than three nodes.\n");
        return;
    }
    struct node* temp = head;
    while(temp->next->next->next != NULL){
        temp = temp->next;
    }
    printf("%d",temp->data);
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
    int choice;
    printf("do you want to swap smallest to first(enter 1):\n");
    printf("do you want to swap largest to last(enter 2):\n");
    printf("Not want to swap(enter 0):\n");
    scanf("%d",&choice);
    if(choice == 1){
        swapSmallestToFirst(head);
        printlist(head);
    }else if(choice == 2){
        swapLargestTolast(head);
        printlist(head);
        printf("\n");
    }else{
        printf("no changes\n");
        printlist(head);
        printf("\n");
    }
    lengthofLL(head);
    printf("\n");
    lastThirdNode(head);
    printf("\n");
    splittingLLEvenOdd(head);
    printf("\n");
    return 0;
}