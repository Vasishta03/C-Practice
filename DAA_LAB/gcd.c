#include <stdio.h>

int min(int number1, int number2){
    return (number1<number2)?number1:number2;
}

int GCD(int number1, int number2){
    int opercount = 0;
    int nmin = min(number1,number2);
    for(;nmin > 0;nmin--){
        opercount++;
        if((number1 % nmin == 0) && (number2 % nmin == 0))return opercount;
    }
}

int main(){
    int TestCases;
    printf("Enter no of TestCases: ");scanf("%d",&TestCases);
    int nums1[TestCases],nums2[TestCases];
    for(int i = 0; i < TestCases; i++){
        printf("Enter TestCase %d number1: ",i+1);scanf("%d",&nums1[i]);
        printf("Enter TestCase %d number2: ",i+1);scanf("%d",&nums2[i]);
    }
    for(int i = 0; i < TestCases; i++){
        int ops = GCD(nums1[i],nums2[i]);
        printf("(m+n): %d ops: %d \n",nums1[i]+nums2[i],ops);
    }
}
