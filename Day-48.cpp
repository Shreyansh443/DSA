#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursive call
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver code
int main() {
    // Creating tree:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    int result = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", result);

    return 0;
}