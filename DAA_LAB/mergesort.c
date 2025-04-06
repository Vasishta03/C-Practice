// Merge Sort Core Logic
void merge(int arr[], int l, int m, int r) {
    // Create temp arrays L[] and R[]
    // Merge while sorting using dual pointers
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
// Divide & Conquer: Recursive structure with base case → divide → combine

int opcount = 0;

void merge(int arr[], int l, int m, int r){
    int n1 = m -l + 1;
    int n2 = r - m;
    int R[n1],S[n2];
    for(int i = 0;i<n1;i++)R[i]=arr[l+i];
    for(int j = 0;j<n2;j++)S[j]=arr[m+j+1];

    int i=0,j=0,k =0;
    while(i<n1 && j<n2){
        if(R[i] <= S[j]){
            arr[l+k] = R[i];
            i++;opcount++;
        }
        else{
            arr[l+k] = S[j];
            j++;opcount++;
        }
        k++;
    }
    while(i < n1){
        arr[l+k] = R[i];
        i++;k++;opcount++;
    }
    while(j < n2){
        arr[l+k] = S[i];
        j++;k++;opcount++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main() {
    int NoOfSamples;
    printf("Enter No of Samples: ");scanf("%d",&NoOfSamples);
    for(int i = 1;i <= NoOfSamples;i++){
        int arr[i*5];
        for(int j=0;j<i*5;j++)arr[j] = (i*5)-1-j;
        opcount = 0;
        mergesort(arr,0,(i*5)-1);
        for(int j=0;j<i*5;j++)printf("%d,",arr[j]);
        printf(" N: %d ,OpCount: %d\n",i*5,opcount);
    }
    return 0;
}
