#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array\n");
    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d ", arr[0]);
    for (int i = 1; i<n; i++){
        if (arr[i] != arr[i-1]){
            printf("%d ", arr[i]);
        }
    }
    return 0;
}