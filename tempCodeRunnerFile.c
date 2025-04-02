#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *nnode, *head = NULL, *tail = NULL;

void insertion(int data)
{
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = NULL;

    if (head == NULL)
    {
        head = tail = nnode;
    }
    else
    {
        tail->next = nnode;
        tail = nnode;
    }
}

void deletion(int pos)
{
    int i;
    tail = head;
    if (pos == 1)
    {
        head = head->next;
        free(tail);
    }
    else
    {
        struct node *prev = NULL;
        for (i = 1; tail != NULL && i < pos; i++)
        {
            prev = tail;
            tail = tail->next;
        }
        if (tail == NULL)
        {
            printf("Invalid position!\n");
            return;
        }
        prev->next = tail->next;
        free(tail);
    }
}

void reverseList()
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printlist()
{
    tail = head;
    printf("List is:\n");
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->next;
    }
    printf("\n");
}

int linkedListToArray(struct node *head, int arr[])
{
    int i = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    return i;
}

void arraytolinkedlist(int arr[], int size, struct node *head)
{
    int i;
    struct node *temp = head;
    for (i = 0; i < size; i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
}
void merge(int arr[], int l, int mid, int R)
{
    int i, j;
    int k = 0;
    int temp[R + 1];
    for (i = 0; i < R; i++)
    {
        temp[i] = arr[i];
    }

    i = l, j = mid + 1;
    while (i <= mid && j <= R)
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i];
        }
        else
        {
            temp[k++] = arr[j++];
        }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= R)
    {
        temp[k++] = arr[j++];
    }
}

void mergesort(int arr[], int l, int R)
{
    if (l < R)
    {
        int mid = l + (R - l) / 2;

        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, R);
        merge(arr, l, mid, R);
    }
}

void sortLL(struct node* head)
{
    int arr[1000];
    int size = linkedListToArray(head, arr);
    mergesort(arr,0,size-1);
    arraytolinkedlist(arr,size,head);
    printlist(head);
}

int main()
{
    insertion(10);
    insertion(200);
    insertion(30);
    insertion(20);
    printlist();
    deletion(4);
    printlist();
    reverseList();
    printlist();

    sortLL(head);

    return 0;
}
