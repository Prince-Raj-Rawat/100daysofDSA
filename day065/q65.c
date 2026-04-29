#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int n, int adj[n][n], int visited[n]) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, n, adj, visited)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
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

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n, adj, visited)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
