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
    int k;
    printf("Enter the number to be searched\n");
    scanf("%d", &k);
    int count=0;
    for (int i = 0; i<n; i++){
        if (arr[i]==k){
            printf("Found at index %d\n", i);
        }
        count++;
    }
    printf("Comparisons = %d\n", count);
    return 0;

}
