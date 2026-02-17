#include <stdio.h>
int main(){
    int n, m;
    printf("Enter the rows of both the matrices\n");
    scanf("%d", &n);
    printf("Enter the colums of both the matrices\n");
    scanf("%d", &m);
    int a[n][m];
    int b[n][m];
    printf("Enter the elements of first matricx\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of second matrix\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &b[i][j]);
        }
    }
    int arr[n][m] = {0};
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            arr[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("The resultant matix :\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            printf(" %d ",arr[i][j] );
        }
        printf("\n");
    }
    return 0;    
}