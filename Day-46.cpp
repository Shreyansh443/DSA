#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation
#define MAX 1000

struct Queue {
    struct TreeNode* arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            printf("%d ", node->val);

            if (node->left)
                enqueue(&q, node->left);

            if (node->right)
                enqueue(&q, node->right);
        }
        printf("\n"); // new level
    }
}

// Example usage
int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);

    return 0;
}