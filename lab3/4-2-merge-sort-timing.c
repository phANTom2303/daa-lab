#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

double mergeSortTime(int *arr, int n) {
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void displayResults(double *results, int n) {
    for (int i = 0; i < n; i++) printf("%f\n", results[i]);
    printf("\n");
}

int main() {
    int t;
    printf("Enter test cases : \n");
    scanf("%d", &t);
    double worstCaseResults[t];
    double avgResults[t];
    double bestResults[t];
    for (int i = 0; i < t; i++) {
        int n;
        printf("\nEnter N : \n");
        scanf("%d", &n);

        int *a1 = (int *)malloc(n * sizeof(int));
        int *a2 = (int *)malloc(n * sizeof(int));
        int *a3 = (int *)malloc(n * sizeof(int));
        srand(time(0));  // Seed random number generator
        for (int i = 0; i < n; i++) {
            a1[i] = i;
            a2[i] = rand() % n;
            a3[i] = n - i;
        }

        bestResults[i] = mergeSortTime(a1, n);
        avgResults[i] = mergeSortTime(a2, n);
        worstCaseResults[i] = mergeSortTime(a3, n);
    }
    printf("\nBest Case Times : \n");
    displayResults(bestResults, t);
    printf("\nAverage Case Times : \n");
    displayResults(avgResults, t);
    printf("\nWorst Case Times : \n");
    displayResults(worstCaseResults, t);
}