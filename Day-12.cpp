#include <stdio.h>

int main(){
    int n, m;

    printf("Enter rows of matrix:\n");
    scanf("%d", &n);

    printf("Enter columns of matrix:\n");
    scanf("%d", &m);
    if (n != m) {
        printf("Matrix is not symmetric (not square).\n");
        return 0;
    }

    int a[n][m];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != a[j][i]){
                printf("Matrix is not symmetric.\n");
                return 0;
            }
        }
    }

    printf("Matrix is symmetric.\n");

    return 0;
}
