#include <stdio.h>

#define MAX 100000

int maxLenZeroSumSubarray(int arr[], int n) {
    int prefix_sum = 0;
    int max_len = 0;

    // Initialize hash array with -1
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -1;

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum is 0
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // Case 2: prefix sum seen before
        if (hash[prefix_sum + offset] != -1) {
            int prev_index = hash[prefix_sum + offset];
            if (i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            // store first occurrence
            hash[prefix_sum + offset] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSumSubarray(arr, n);
    printf("%d\n", result); // Output: 5

    return 0;
}