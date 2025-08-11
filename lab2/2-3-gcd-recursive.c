#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int main() {
    int a, b;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &a, &b);
    printf("GCD = %d", gcd(a, b));
}