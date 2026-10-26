#include <stdio.h>
#define INF 999999
int main(){
    int n, i, j, min, u, v;
    int cost[20][20], visited[20] = {0};
    int edges = 0, minCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;}}
    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        u = -1;
        v = -1;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u == -1) {
            printf("Graph is disconnected!\n");
            return 0;}
        printf("%d - %d : %d\n", u, v, min);
        minCost += min;
        visited[v] = 1;
        edges++;}
    printf("Minimum cost = %d\n", minCost);
    return 0;}