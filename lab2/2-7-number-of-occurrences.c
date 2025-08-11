#include <stdio.h>
#include <stdlib.h>

int searchFirst(int *arr, int target, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        int answer = mid;
        int possibleAnswer = searchFirst(arr, target, low, mid - 1);
        if (possibleAnswer != -1)
            return (answer < possibleAnswer) ? answer : possibleAnswer;
        else
            return answer;
    } else if (target > arr[mid])
        return searchFirst(arr, target, mid + 1, high);
    else
        return searchFirst(arr, target, low, mid - 1);
}

int searchLast(int *arr, int target, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    // printf("Mid = %d", mid);
    if (arr[mid] == target) {
        int answer = mid;
        int possibleAnswer = searchLast(arr, target, mid + 1, high);
        if (possibleAnswer != -1)
            return (answer > possibleAnswer) ? answer : possibleAnswer;
        else
            return answer;
    } else if (target > arr[mid])
        return searchLast(arr, target, mid + 1, high);
    else
        return searchLast(arr, target, low, mid - 1);
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

    int target;
    printf("Enter Target : ");
    scanf("%d", &target);

    int firstPos = searchFirst(arr, target, 0, n - 1);
  

    int lastPos = searchLast(arr, target, 0, n - 1);

    int occurrences = 0;
    if(firstPos != -1)
        occurrences = lastPos - firstPos + 1;
    printf("Number of occurences of %d is  : %d \n", target, occurrences);
}