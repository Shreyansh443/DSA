#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Simple hash table size
#define HASH_SIZE 200003

int hashTable[HASH_SIZE];

// Hash function
int hash(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix_sum = 0;
    long long count = 0;

    // Initialize hash table to 0
    for(int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = 0;

    // Important: prefix sum 0 occurs once
    hashTable[hash(0)] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        int index = hash(prefix_sum);

        // If prefix_sum seen before
        count += hashTable[index];

        // Increase frequency
        hashTable[index]++;
    }

    printf("%lld\n", count);

    return 0;
}