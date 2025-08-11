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
    printf("Enter N elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    
    int *counted = (int *)malloc(n * sizeof(int));
    int lastIdx = -1;
    int maxCount = 0, maxCountPos = 0;
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        bool alreadyCounted = false;
        for (int j = 0; j < lastIdx; j++) {
            if (counted[j] == curr) {
                alreadyCounted = true;
                break;
            }
        }

        if (alreadyCounted)
            continue;

        int count = 0;
        for (int j = i; j <= n; j++) {
            if (arr[j] == curr)
                count++;
        }

        printf("%d occured %d tims\n", curr, count);

        if (count > maxCount) {
            maxCount = count;
            maxCountPos = i;
        }

        counted[++lastIdx] = curr;
    }

    printf("Most Repeating Element : %d\n", arr[maxCountPos]);
    printf("\n");
}