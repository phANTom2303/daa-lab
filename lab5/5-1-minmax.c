#include <stdio.h>
#include <stdlib.h>

int* findMinMax(int* arr, int low, int high) {
    int* res = (int*)malloc(2 * sizeof(int));
    if (high - low > 1) {
        int mid = low + (high - low) / 2;
        int* mm1 = findMinMax(arr, low, mid);
        int* mm2 = findMinMax(arr, mid + 1, high);

        res[0] = (mm1[0] < mm2[0]) ? mm1[0] : mm2[0];
        res[1] = (mm1[1] > mm2[1]) ? mm1[1] : mm2[1];
        return res;
    } else if (high - low == 1) {
        res[0] = (arr[high] < arr[low]) ? arr[high] : arr[low];
        res[1] = arr[high] + arr[low] - res[0];
        return res;
    } else {
        res[0] = arr[low];
        res[1] = arr[high];
        return res;
    }
}
int main() {
    int n;
    printf("Enter N : \n");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d numbers : \n ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int* minmax = findMinMax(arr, 0, n - 1);
    printf("Minimum = %d \n", minmax[0]);
    printf("Maximum = %d \n", minmax[1]);
}