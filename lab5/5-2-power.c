#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int powerDAQ(int a, int n) {
    if (n == 0)
        return 1;

    int halfPow = powerDAQ(a, n / 2);
    int result = halfPow * halfPow;
    if (n % 2 == 1)
        return result * a;
    else
        return result;
}

int powerRec(int a, int n) {
    if (n == 0)
        return 1;
    return a * powerRec(a, n - 1);
}

void compareTiming(int a, int n) {
    clock_t start = clock();
    int daqVal = powerDAQ(a, n);
    clock_t end = clock();
    double daqTime = (double)(end - start) / CLOCKS_PER_SEC;

    clock_t start2 = clock();
    int recVal = powerRec(a, n);
    clock_t end2 = clock();
    double recTime = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // printf("DAQ Result: %d\n", daqVal);
    // printf("Recursive Result: %d\n", recVal);
    printf("DAQ time: %.6f s\nRecursive time: %.6f s\n", daqTime, recTime);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, n;
        // printf("Enter a followed by n:\n");
        scanf("%d %d", &a, &n);
        compareTiming(a, n);
    }
}