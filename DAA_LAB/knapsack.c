#include <stdio.h>

#define SIZE 3

int knapsack(int W, int val[], int wei[]) {
    int sack[W];
    for(int i = 0; i < W; i++)
        sack[W] = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = W; j >= wei[i]; j--) {
            int temp = sack[j - wei[i]] + val[i];
            sack[j] = temp > sack[j] ? temp : sack[j];
        }

    return sack[W];
}

void main() {
    int val[SIZE] = {3, 2, 1};
    int wei[SIZE] = {1, 5, 4};
    int W = 5;

    printf("Max value: %d\n", knapsack(W, val, wei));
}
