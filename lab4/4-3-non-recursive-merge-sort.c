#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));
    int pos = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[pos++] = arr[left++];
        } else
            temp[pos++] = arr[right++];
    }

    while (left <= mid) temp[pos++] = arr[left++];
    while (right <= high) temp[pos++] = arr[right++];

    pos = 0;
    for (int i = low; i <= high; i++) {
        arr[i] = temp[pos++];
    }
    free(temp);
}
void mergeSort(int *arr, int n) {
    int curr = 2;
    while (curr < n) {
        for (int i = 0; i < n; i += curr) {
            int low = i;
            int high = i + curr - 1;
            if (high > n - 1)
                high = n - 1;
            int mid = low + (high - low) / 2;
            merge(arr, low, mid, high);
        }
        curr *= 2;
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("\nEnter N : \n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Entered Array : \n");
    display(arr, n);
    mergeSort(arr, n);
    printf("Sorted Array : \n");
    display(arr, n);
}
