#include <stdio.h>

int Stack[30],tos=-1;

void DFS(int N,int AdjMat[][N],int Start){
    int PopOrder[20],PushOrder[20],popc=0,pushc=0;
    Stack[++tos] = Start;
    PushOrder[pushc++] = Start;
    int Visited[N];
    for(int i=0;i<N;i++)Visited[i]=0;
    while(tos >= 0){
        int CurNode = Stack[tos--];
        PopOrder[popc++] = CurNode;
        if(Visited[CurNode] == 1)continue;
        for(int i = 0;i<N;i++){
            if(AdjMat[CurNode][i] == 1 && Visited[i] == 0){
                Stack[++tos]=i;
                PushOrder[pushc++] = i;
            }
        }
        Visited[CurNode] = 1;
    }
    printf("Pop Order: ");
    for(int i = 0;i<popc;i++)printf("%d ",PopOrder[i]);
    printf("\n");
    printf("Push Order: ");
    for(int i = 0;i<pushc;i++)printf("%d ",PushOrder[i]);
    printf("\n");
}

int main(){
    int N;
    printf("No of Nodes:");scanf("%d",&N);
    int AdjMat[N][N];
    for(int i = 0; i<N;i++)for(int j = 0; j<N;j++)scanf("%d",&AdjMat[i][j]);
    DFS(N,AdjMat,0);
    return 0;
}
