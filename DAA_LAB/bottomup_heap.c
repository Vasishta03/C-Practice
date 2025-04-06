// heap bottom up algo
#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int n, int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;

    if(left < n && heap[left] > heap[largest])largest = left;
    if(right < n && heap[right] > heap[largest])largest = right;

    if(largest != i){
        swap(&heap[largest],&heap[i]);
        heapifyDown(heap,n,largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = (n-1)/2;i >=0;i--){
        heapifyDown(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    for(int i = n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapifyDown(arr,i,0);
    }
}

int main(){
    int arr[] = {4,3,2,1};
    heapSort(arr,4);
    for(int i = 0;i<4;i++)printf("%d ",arr[i]);

    return 0;
}
