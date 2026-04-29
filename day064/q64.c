#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int n, int adj[n][n], int s) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int queue[MAX], front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal Order:\n");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
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
    printf("Enter source vertex: ");
    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}
