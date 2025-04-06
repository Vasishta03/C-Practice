#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *Array,int length){
    int OpsCount = 0;
    for(int i = 0; i < length; i++)printf("%d ",Array[i]);
    for(int i = 0; i < length-1; i++){
        for (int j = 0; j < length-i-1; j++){
            OpsCount++;
            if(Array[j+1] < Array[j]){
                OpsCount++;
                int temp = Array[j+1];
                Array[j+1] = Array[j];
                Array[j] = temp;
            }
        }
    }
    printf(" OpsCount: %d \n",OpsCount);
}

int main(){
    int N = 5;
    int NoOfSamples;printf("Enter No of Samples:");scanf("%d",&NoOfSamples);
    for(int i = 0; i < NoOfSamples;i++){
        int *Arr = (int*)malloc(N*sizeof(int));
        for(int j = 0;j<N;j++)Arr[j] = N-j;
        BubbleSort(Arr,N);
        N += 5;
    }
    return 0;
}
