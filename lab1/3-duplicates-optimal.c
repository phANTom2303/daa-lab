#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

    printf("\n");

    int maxCount = 0, maxCountPos = 0;
    for (int i = 0; i < n; i++) {
        if (counted[i] == 1)
            continue;
        int curr = arr[i];
        int count = 0;
        for (int j = i; j <= n; j++) {
            if (arr[j] == curr) {
                count++;
                counted[j] = 1;
            }
        }

        printf("%d occured %d tims\n", curr, count);

        if (count > maxCount) {
            maxCount = count;
            maxCountPos = i;
        }
    }

    printf("Most Repeating Element : %d\n", arr[maxCountPos]);
    printf("\n");
}