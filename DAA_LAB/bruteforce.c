
#include <stdio.h>
#include <string.h>

void BruteForceStringMatch(char string[],char search[]){
    int i = 0,j=0,OpsCount = 0;
    int len1 = strlen(string),len2 = strlen(search);
    while(i < len1 && j < len2){
        OpsCount++;
        if(string[i] == search[j]){
            i++;j++;
        }else{
            i++;
        }
    }
    if(j == len2)printf("%s is found between index (%d,%d) OpsCount: %d \n",search,j,i-j-1,OpsCount);
    else printf("%s not found in %s \n",search,string);
}

int main(){
    int N = 5;
    int NoOfSamples;printf("Enter No of Samples:");scanf("%d",&NoOfSamples);
    for(int i = 0; i < NoOfSamples;i++){
        char string[N];
        for(int i = 0;i<N;i++)string[i] = 'a';
        string[N-1] = 'b';
        BruteForceStringMatch(string,"ab");
        N += 5;
    }
    return 0;
}
