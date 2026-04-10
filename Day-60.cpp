#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to count number of nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is complete
bool isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check min-heap property
bool isMinHeap(struct Node* root) {
    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // If only left child
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    // If both children exist
    else {
        if (root->data <= root->left->data &&
            root->data <= root->right->data)
            return isMinHeap(root->left) &&
                   isMinHeap(root->right);
        else
            return false;
    }
}

// Build tree from level order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}