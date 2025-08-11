#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter size of N : ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Invalid size of N\n");
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    int *prefix = (int *)malloc(n* sizeof(int));
    printf("Enter N elements : ");
    for(int i = 0; i < n; i ++)
        scanf("%d",&arr[i]);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i ++){
        prefix[i] = arr[i] + prefix[i - 1];
    }

    printf("Entered and prefix Arrays : \n");
    for(int i = 0; i < n; i ++)
        printf("%d ", arr[i]);
    printf("\n");
     for(int i = 0; i < n; i ++)
        printf("%d ", prefix[i]);
    printf("\n");
    return 0;
}
