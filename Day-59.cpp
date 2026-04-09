#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Last element in postorder is root
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = newNode(curr);

    // If only one node
    if (start == end)
        return node;

    // Find position in inorder
    int pos = search(inorder, start, end, curr);

    // IMPORTANT: build right first (because postorder is L R Root)
    node->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return node;
}

// Preorder traversal (Root Left Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Print preorder traversal
    preorder(root);

    return 0;
}