// Write a program for breadth-first search of a graph.

#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

typedef struct{
    int Arr[Max_Size];
    int front,rear;
}Queue;

void Init_Queue(Queue *q){
    q-> front = -1;
    q->rear = -1;
}
int is_Full(Queue *q){
    return q->rear == Max_Size-1;
}
int is_Empty(Queue *q){
    return q->front == -1;
}

void enqueue(Queue *q,int item){
    if(is_Full(q)){
        printf("Queue is Full!");
        return;
    }
    if(is_Empty(q)){
        q->Arr[++(q->rear)] = item;
        q->front = 0;
        return;
    }
    q->Arr[++(q->rear)] = item;
}

int dequeue(Queue *q){
    if(is_Empty(q)){
        printf("Queue is Empty!");
        exit(0);
    }
    if(q->front == q->rear){
        int temp = q->Arr[(q->front)++];
        q->front = -1;
        q->rear = -1;
        return temp;
    }
    return q->Arr[(q->front)++];
}

// int Queue[20],front = -1,rear = -1;

void BFS(int N,int AdjacencyMatrix[][N],int Start){
    Queue que;
    Init_Queue(&que);
    int PopOrder[20],PushOrder[20],popc=0,pushc=0;
    enqueue(&que,Start);
    PushOrder[pushc++] = Start;
    int VisitedNodes[N];
    for(int i=0;i<N;i++)VisitedNodes[i]=0;
    while(){
        int CurNode = dequeue();
        PopOrder[popc++] = CurNode;
        if(VisitedNodes[CurNode] == 1)continue;
        for(int i = 0;i<N;i++){
            //printf("at node %d, %d,%d rear:%d front:%d \n",CurNode,i,AdjacencyMatrix[CurNode][i],rear,front);
            if(AdjacencyMatrix[CurNode][i] == 1 && VisitedNodes[i] == 0){
                enqueue(i);
                PushOrder[pushc++] = i;
            }
        }
        VisitedNodes[CurNode] = 1;
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
    printf("Enter No of Nodes:");scanf("%d",&N);
    int AdjacencyMatrix[N][N];
    for(int i = 0; i<N;i++)for(int j = 0; j<N;j++)scanf("%d",&AdjacencyMatrix[i][j]);
    BFS(N,AdjacencyMatrix,0);
    return 0;
}
