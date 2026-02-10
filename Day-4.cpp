#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in an array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements inside the array\n");
    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int b = 0;
    int temp = 0;
    for (int i = n-1; i>=b; i--){
        temp = arr[b];
        arr[b] = arr[i];
        arr[i] = temp;
        b++;
    }
    printf("Swapped array :\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}