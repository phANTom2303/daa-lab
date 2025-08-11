#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int target, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (target > arr[mid])
        return search(arr, target, mid + 1, high);
    else
        return search(arr, target, low, mid - 1);
}

int main() {
    int n;
    printf("Enter N : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter Target : ");
    scanf("%d", &target);

    int result = search(arr, target, 0, n - 1);
    if (result == -1)
        printf("Element Not Found\n");
    else
        printf("Element Found at %d\n", result);
}