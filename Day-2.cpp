#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i<n; i++){
        scanf("%d",  &a[i] );
    }
    int p;
    printf("Enter the position where the element is to be deleted\n");
    scanf("%d", &p);
    p = p-1;
    for (int i=p; i<n; i++){
        a[i] = a[i+1];
    }
    for (int i=0; i<n-1; i++){
        printf("%d ",a[i] );
    }
    return 0;

}