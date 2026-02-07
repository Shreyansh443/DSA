#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    int a[n+1];
    printf("Enter the elements of the array\n");
    for (int i = 0; i<n; i++){
        scanf("%d",  &a[i] );
    }
    int p;
    printf("Enter the position where the element is to be inserted\n");
    scanf("%d", &p);
    p = p-1;
    int x;
    printf("Enter the element to be inserted\n");
    scanf("%d", &x);
    int z;
    for (int i=n; i>p; i--){
        a[i] = a[i-1];
    }
    a[p] = x;
    for (int i=0; i<n+1; i++){
        printf(" %d ", a[i] );
    }
    return 0;

}