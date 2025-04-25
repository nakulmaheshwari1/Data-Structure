#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QNode {
    char* bin;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* createNode(char* bin) {
    struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
    temp->bin = (char*) malloc(strlen(bin) + 1);
    strcpy(temp->bin, bin);
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, char* bin) {
    struct QNode* temp = createNode(bin);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

char* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QNode* temp = q->front;
    char* bin = temp->bin;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return bin;
}

void generateBinary(int n) {
    struct Queue* q = createQueue();
    enqueue(q, "1");

    for (int i = 1; i <= n; i++) {
        char* current = dequeue(q);
        printf("%s\n", current);

        char* bin0 = (char*) malloc(strlen(current) + 2);
        char* bin1 = (char*) malloc(strlen(current) + 2);
        sprintf(bin0, "%s0", current);
        sprintf(bin1, "%s1", current);

        enqueue(q, bin0);
        enqueue(q, bin1);

        free(current);
        free(bin0);
        free(bin1);
    }

    free(q);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Binary numbers from 1 to %d:\n", n);
    generateBinary(n);
    return 0;
}
