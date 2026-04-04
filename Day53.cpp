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

// Queue for building tree + traversal
struct Pair {
    struct TreeNode* node;
    int hd;
};

struct Queue {
    struct Pair arr[2000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct Pair dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q).node;

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalTraversal(struct TreeNode* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    // Map (HD shifted by +1000)
    int map[2001][100];
    int size[2001] = {0};

    enqueue(&q, root, 1000);

    int minHD = 1000, maxHD = 1000;

    while (!isEmpty(&q)) {
        struct Pair p = dequeue(&q);
        struct TreeNode* node = p.node;
        int hd = p.hd;

        map[hd][size[hd]++] = node->val;

        if (node->left) {
            enqueue(&q, node->left, hd - 1);
            if (hd - 1 < minHD) minHD = hd - 1;
        }

        if (node->right) {
            enqueue(&q, node->right, hd + 1);
            if (hd + 1 > maxHD) maxHD = hd + 1;
        }
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    verticalTraversal(root);

    return 0;
}