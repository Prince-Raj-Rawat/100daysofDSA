#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter adjacency matrix (%d x %d), use -1 for no edge:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j) graph[i][j] = INF;
            else graph[i][j] = val;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] >= INF/2) printf("-1 ");
            else printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
