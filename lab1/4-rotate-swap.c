#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotateArray(int *arr, int n, int pos) {
    for (int i = pos - 2; i >= 0; i--) {
        swap(&arr[i], &arr[i + 1]);
    } 
}

int main() {
    int n;
    printf("Enter size of N : ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size of N\n");
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    int *counted = (int *)malloc(n * sizeof(int));
    printf("Enter N elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        counted[i] = 0;
    }

    int pos;
    printf("Enter positions to swap : ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n) {
        printf("Invalid value of Pos");
        return 0;
    }

    rotateArray(arr, n, pos);

    printf("Rotated Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
