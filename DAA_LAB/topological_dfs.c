#include <stdio.h>
#include <stdlib.h>

int a[50][50], visited[50], stack[100],n,t=0;

void dfs(int v){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(a[v][i] && !visited[i]){
            dfs(i);
        }
    }
    stack[t++]=v;
}

int main(){
    printf("Enter the Number of Vertices : ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix : \n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i<n; i++){if(!visited[i])dfs(i);}

    printf("The Topological Sort Order is(DFS Method) : ");
    for(int i=n-1;i>=0;i--)printf("%d ",stack[i]);

    printf("\n");
    return 0;
}
