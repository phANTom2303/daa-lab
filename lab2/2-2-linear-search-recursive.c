#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int n, int target, int pos) {
    if (pos < n) {
        if (arr[pos] == target) {
            return pos;
        } else {
            search(arr, n, target, pos + 1);
        }
    } else {
        return -1;
    }
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

    int result = search(arr, n, target, 0);
    if (result == -1)
        printf("Element Not Found\n");
    else
        printf("Element Found at %d\n", result);
}