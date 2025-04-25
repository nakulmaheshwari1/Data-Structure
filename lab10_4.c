//To find the depth of binary tree
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}



int depth(struct Node* root, int value, int currentDepth) {
    if (root == NULL) return -1;
    if (root->data == value) return currentDepth;

    int left = depth(root->left, value, currentDepth + 1);
    if (left != -1) return left;

    return depth(root->right, value, currentDepth + 1);
}

int main() {
    

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Depth of node 5: %d\n", depth(root, 5, 0));

    return 0;
}
