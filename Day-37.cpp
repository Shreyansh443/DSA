#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX];
int size = 0;

// Insert element
void insert(int x) {
    arr[size] = x;
    size++;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0)
        return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete minimum element
void deleteMin() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", arr[minIndex]);

    // Shift elements
    for (int i = minIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Peek minimum element
void peek() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", arr[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    char operation[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(operation, "delete") == 0) {
            deleteMin();
        }
        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}