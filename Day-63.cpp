#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph, add reverse edge
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function using recursion
void DFS(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edges, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // adjacency list
    struct Node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(s, adj, visited);

    return 0;
}