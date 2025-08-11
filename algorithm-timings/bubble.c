#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double bubbleSortTime(int *arr, int n) {
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
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

        bestResults[i] = bubbleSortTime(a1, n);
        avgResults[i] = bubbleSortTime(a2, n);
        worstCaseResults[i] = bubbleSortTime(a3, n);
    }
    printf("\nBest Case Times : \n");
    displayResults(bestResults, t);
    printf("\nAverage Case Times : \n");
    displayResults(avgResults, t);
    printf("\nWorst Case Times : \n");
    displayResults(worstCaseResults, t);
}