#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int *dist = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("\nResult: NEGATIVE CYCLE detected in the graph.\n");
            free(dist);
            return;
        }
    }

    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("Vertex %d: INF (unreachable)\n", i);
        else printf("Vertex %d: %d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge *edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    printf("Enter each edge as: u v w\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    free(edges);
    return 0;
}
