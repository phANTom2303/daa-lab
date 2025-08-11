#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    while (1) {
        int mid = low + (high - low) / 2;
        if (low >= high && arr[mid] != target) {
            return -1;
        }
        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else if (target < arr[mid]) {
            high = mid - 1;
        }
    }
}

int lsearch(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int t;
    printf("Enter test cases : \n");
    scanf("%d", &t);
    double linearResults[t];
    double binaryResults[t];
    for (int i = 0; i < t; i++) {
        int n;
        printf("\nEnter N : \n");
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        int target = arr[n / 2];

        printf("\nFor %d : \n", n);
        clock_t start_linear = clock();
        int ans = lsearch(arr, n, target);
        clock_t end_linear = clock();
        double linear_time =
            (double)(end_linear - start_linear) / CLOCKS_PER_SEC;
        printf("\nLinear Search Time: %f seconds", linear_time);
        linearResults[i] = linear_time;

        clock_t start_binary = clock();
        ans = binsearch(arr, n, target);
        clock_t end_binary = clock();
        double binary_time =
            (double)(end_binary - start_binary) / CLOCKS_PER_SEC;
        printf("\nBinary Search Time: %f seconds", binary_time);
        binaryResults[i] = binary_time;
    }
    printf("Linear Results : \n");
    for (int i = 0; i < t; i++) printf("%f\n", linearResults[i]);
    printf("Binary Results : \n");
    for (int i = 0; i < t; i++) printf("%f\n", binaryResults[i]);
}