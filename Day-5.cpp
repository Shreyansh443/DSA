#include <stdio.h>

int main() {
    int p, q;
    printf("Enter the no of elements in first array\n");
    scanf("%d", &p);
    printf("Enter elements in first array\n");
    int arr1[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the no of elements in first array\n");
    scanf("%d", &q);
    int arr2[q];
    printf("Enter elements in first array\n");
    for(int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0;

    while(i < p && j < q) {
        if(arr1[i] <= arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        } else {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    while(i < p) {
        printf("%d ", arr1[i]);
        i++;
    }

    while(j < q) {
        printf("%d ", arr2[j]);
        j++;
    }

    return 0;
}
