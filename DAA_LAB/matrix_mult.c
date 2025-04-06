#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int opcount = 0;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    opcount++;
    for (int j = low; j <= high - 1; j++) {
        opcount++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int NoOfSamples;
    printf("Enter No of Samples: ");scanf("%d",&NoOfSamples);
    for(int i = 1;i <= NoOfSamples;i++){
        int arr[i*5];
        for(int j=0;j<i*5;j++)arr[j] = (i*5)-1-j;
        opcount = 0;
        quickSort(arr,0,(i*5)-1);
        for(int j=0;j<i*5;j++)printf("%d,",arr[j]);
        printf(" N: %d ,OpCount: %d\n",i*5,opcount);
    }
    return 0;
}
