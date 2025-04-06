// max heap top down algorithm
#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index){
    int parent = (index - 1)/2;
    if(index > 0 && heap[parent] < heap[index]){
        swap(&heap[parent],&heap[index]);
        heapifyUp(heap,parent);
    }
}

void insertHeap(int heap[], int *size, int item){
    heap[(*size)++] =  item;
    heapifyUp(heap,(*size)-1);
}

int main(){
    int heap[20];
    int size = 0;
    insertHeap(heap,&size,56);
    insertHeap(heap,&size,6);
    insertHeap(heap,&size,5);
    insertHeap(heap,&size,84);
    for(int i=0;i<size;i++)printf("%d ",heap[i]);

}
