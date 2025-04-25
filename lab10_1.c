//write  function to insert a node into binary tree and traverse it in 1.pre order 2.preorder 3.postorder
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


#define SIZE 100

struct Node* queue[SIZE];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear < SIZE - 1) {
        queue[++rear] = node;
    }
}

struct Node* dequeue() {
    if (front < rear) {
        return queue[++front];
    }
    return NULL;
}

int isQueueEmpty() {
    return front == rear;
}


struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    if (!root)
        return newNode;

    front = rear = -1; 
    enqueue(root);

    while (!isQueueEmpty()) {
        struct Node* temp = dequeue();

        if (!temp->left) {
            temp->left = newNode;
            return root;
        } else {
            enqueue(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return root;
        } else {
            enqueue(temp->right);
        }
    }
    return root;
}


void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct Node* root = NULL;

    int values[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Pre-order Traversal:\n");
    preorder(root);
    printf("\nIn-order Traversal:\n");
    inorder(root);
    printf("\nPost-order Traversal:\n");
    postorder(root);

    return 0;
}
