#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int adj[n][n], int visited[n]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nDFS Traversal Order:\n");
    dfs(s, n, adj, visited);
    printf("\n");

    return 0;
}
