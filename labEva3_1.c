#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isBSTUtil(struct Node* root, int* prev) {
    if (root == NULL)
        return 1;

    if (!isBSTUtil(root->left, prev))
        return 0;

    if (root->data <= *prev)
        return 0;

    *prev = root->data;
    return isBSTUtil(root->right, prev);
}

int isBST(struct Node* root) {
    int prev = INT_MIN;
    return isBSTUtil(root, &prev);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->right->left = createNode(12);

    if (isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is NOT a BST\n");

    return 0;
}
