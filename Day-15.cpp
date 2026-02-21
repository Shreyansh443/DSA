#include <stdio.h>

int main() {
    int m, n;
    
    printf("Enter the number of rows and colums\n");
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    int sum = 0;

    // Input matrix elements
    printf("Enter the elemnts of the matrix\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    // Print result
    printf("%d\n", sum);

    return 0;
}