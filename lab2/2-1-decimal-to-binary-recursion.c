#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void convertToBinary(int num, char *res, int pos) {
    if (num > 0) {
        int rem = num % 2;
        if (rem == 0)
            res[pos] = '0';
        else
            res[pos] = '1';
        convertToBinary(num / 2, res, pos - 1);
    }
}

int main() {
    int n;
    printf("Enter N : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Converted Numbers : ");
    for (int i = 0; i < n; i++) {
        char *binary = (char *)malloc(32 * sizeof(char));
        for (int j = 0; j < 32; j++) binary[j] = '0';

        convertToBinary(arr[i], binary, 31);

        printf("%d = %s", arr[i], binary);
    }
}