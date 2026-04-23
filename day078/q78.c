#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1000

struct Edge {
    int v, w;
    struct Edge* next;
};

struct Edge* addEdge(struct Edge* head, int v, int w) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = head;
    return newEdge;
}

int primMST(struct Edge* adj[], int n) {
    int key[n+1], inMST[n+1];
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }
    key[1] = 0; 

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
 
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = 1;
        totalWeight += key[u];

        struct Edge* e = adj[u];
        while (e != NULL) {
            int v = e->v;
            int w = e->w;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
            }
            e = e->next;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Edge* adj[n+1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u] = addEdge(adj[u], v, w);
        adj[v] = addEdge(adj[v], u, w); // undirected
    }

    int result = primMST(adj, n);
    printf("%d\n", result);

    for (int i = 1; i <= n; i++) {
        struct Edge* e = adj[i];
        while (e != NULL) {
            struct Edge* temp = e;
            e = e->next;
            free(temp);
        }
    }

    return 0;
}
