#include <stdio.h>
#include <stdlib.h>


int main() {
    int *arr = (int *)malloc(10 * sizeof(int));
    printf("Enter 10 numbers : ");
    for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);
    printf("\n");
    int maxPos = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > arr[maxPos])
            maxPos = i;
    }

    int secMaxPos = (maxPos == 0) ? 1 : 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > arr[secMaxPos] && arr[i] < arr[maxPos])
            secMaxPos = i;
    }
    printf("Largest = %d\n2nd Largest = %d\n", arr[maxPos], arr[secMaxPos]);
    printf("\n");
    return 0;
}