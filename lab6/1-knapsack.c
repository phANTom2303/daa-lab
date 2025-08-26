#include <stdio.h>
#include <stdlib.h>

struct item {
    float ratio;
    int profit;
    int weight;
    int index;
};

void displayItems(struct item *arr, int n) {
    printf("Index\tRatio\tProfit\tWeight\n");
    printf("-----\t-----\t------\t------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%d\t%d\n", arr[i].index, arr[i].ratio, arr[i].profit,
               arr[i].weight);
    }
}

void merge(struct item *arr, int low, int mid, int high, int sortBy) {
    int left = low, right = mid + 1;
    struct item *temp =
        (struct item *)malloc((high - low + 1) * sizeof(struct item));
    int pos = 0;
    while (left <= mid && right <= high) {
        int condition = 0;
        switch(sortBy) {
            case 1: // Sort by ratio
                condition = (arr[left].ratio <= arr[right].ratio);
                break;
            case 2: // Sort by profit
                condition = (arr[left].profit <= arr[right].profit);
                break;
            case 3: // Sort by weight
                condition = (arr[left].weight <= arr[right].weight);
                break;
        }
        
        if (condition) {
            temp[pos++] = arr[left++];
        } else {
            temp[pos++] = arr[right++];
        }
    }

    while (left <= mid) temp[pos++] = arr[left++];
    while (right <= high) temp[pos++] = arr[right++];

    pos = 0;
    for (int i = low; i <= high; i++) {
        arr[i] = temp[pos++];
    }
    free(temp);
}

void mergeSort(struct item *arr, int low, int high, int sortBy) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, sortBy);
    mergeSort(arr, mid + 1, high, sortBy);
    merge(arr, low, mid, high, sortBy);
}

void copyItems(struct item *dest, struct item *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

float calculateProfit(struct item *items, int n, int w, int method) {
    int remainingWeight = w;
    float profit = 0;
    
    if (method == 1) { // Ratio-based (fractional knapsack)
        for (int i = n - 1; i >= 0; i--) {
            if (items[i].weight <= remainingWeight) {
                profit += items[i].profit;
                remainingWeight -= items[i].weight;
            } else if (remainingWeight > 0) {
                profit += ((float)remainingWeight / items[i].weight) * items[i].profit;
                break;
            }
        }
    } else { // Profit or weight-based (0/1 knapsack)
        for (int i = n - 1; i >= 0; i--) {
            if (items[i].weight <= remainingWeight) {
                profit += items[i].profit;
                remainingWeight -= items[i].weight;
            }
        }
    }
    
    return profit;
}

int main() {
    int n;
    printf("Enter Number of items : \n");
    scanf("%d", &n);
    int w;
    printf("Enter weight limit W : \n");
    scanf("%d", &w);

    int *profits = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));
    printf("Enter n profits : ");
    for (int i = 0; i < n; i++) scanf("%d", &profits[i]);
    printf("Enter n wieghts : ");
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);

    struct item items[n], itemsByProfit[n], itemsByWeight[n];
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)profits[i] / weights[i];
        items[i].profit = profits[i];
        items[i].weight = weights[i];
        items[i].index = i;
    }

    // Copy items for different sorting approaches
    copyItems(itemsByProfit, items, n);
    copyItems(itemsByWeight, items, n);

    // 1. Sort by ratio (original approach)
    mergeSort(items, 0, n - 1, 1);
    printf("\n--- Greedy by Ratio (per unit weight) ---\n");
    // displayItems(items, n);
    float profitByRatio = calculateProfit(items, n, w, 1);
    printf("Maximum profit Obtained (Greedy per unit weight): %.2f\n", profitByRatio);

    // 2. Sort by profit
    mergeSort(itemsByProfit, 0, n - 1, 2);
    printf("\n--- Greedy by Profit (highest profit first) ---\n");
    // displayItems(itemsByProfit, n);
    float profitByProfit = calculateProfit(itemsByProfit, n, w, 2);
    printf("Maximum profit Obtained (Greedy by profit): %.2f\n", profitByProfit);

    // 3. Sort by weight
    mergeSort(itemsByWeight, 0, n - 1, 3);
    printf("\n--- Greedy by Weight (lightest first) ---\n");
    // displayItems(itemsByWeight, n);
    float profitByWeight = calculateProfit(itemsByWeight, n, w, 3);
    printf("Maximum profit Obtained (Greedy by weight): %.2f\n", profitByWeight);

    free(profits);
    free(weights);
    return 0;
}