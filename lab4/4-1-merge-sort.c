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
void mergeSort(int *arr, int low, int high) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);
    printf("Sorted Array : \n");
    display(arr, n);
}
