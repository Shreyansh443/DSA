#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Declare adjacency matrix
    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;
    int type;

    // Ask graph type
    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &type);

    // Input edges
    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(type == 0) {
            adj[v][u] = 1;  // For undirected graph
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}