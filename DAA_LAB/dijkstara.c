#include <stdio.h>

#define MAX 4

int opCount = 0;

void dijkstra(int G[MAX][MAX], int startnode) {
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visited[MAX], minDist, nextNod;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (G[i][j] == 0)
                cost[i][j] = 999999;
            else
                cost[i][j] = G[i][j];

    opCount = MAX * (MAX + 1);
    for (int i = 0; i < MAX; i++) {
        dist[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    dist[startnode] = 0;
    visited[startnode] = 1;

    for (int count = 1; count < MAX - 1; count++) {
        minDist = 999999;
        for (int i = 0; i < MAX; i++)
            if (dist[i] < minDist && !visited[i]) {
                minDist = dist[i];
                nextNod = i;
                opCount++;
            }

        visited[nextNod] = 1;
        for (int i = 0; i < MAX; i++)
            if (!visited[i])
                if (minDist + cost[nextNod][i] < dist[i]) {
                    dist[i] = minDist + cost[nextNod][i];
                    pred[i] = nextNod;
                    opCount += 2;
                }
    }

    for (int i = 0; i < MAX; i++) {
        if (i != startnode) {
            if (dist[i] == 9999) {
                printf("No path for: %d, %d\n", i, startnode);
            } else {
                printf("Cost from %d: %d", i, dist[i]);
                printf("\nPath: %d", i);
                int j = i;
                do {
                    j = pred[j];
                    printf(" -> %d", j);
                } while (j != startnode);
            }
            printf("\n");
        }
    }
}

void main() {
    int G[MAX][MAX] = {
        {0, 3, 0, 2},
        {3, 0, 1, 0},
        {0, 1, 0, 5},
        {2, 0, 5, 0}
    };

    int u;
    printf("Enter start: ");
    scanf("%d", &u);

    dijkstra(G, u);
    printf("Op. count: %d\n", opCount);
}
