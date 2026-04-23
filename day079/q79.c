#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int v, w;
    struct Edge* next;
};

struct Node {
    int vertex;
    int dist;
};

struct Heap {
    struct Node* arr;
    int size;
};

struct Edge* addEdge(struct Edge* head, int v, int w) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = head;
    return newEdge;
}

void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Heap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < heap->size && heap->arr[l].dist < heap->arr[smallest].dist) smallest = l;
    if (r < heap->size && heap->arr[r].dist < heap->arr[smallest].dist) smallest = r;
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

struct Node extractMin(struct Heap* heap) {
    struct Node root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

void decreaseKey(struct Heap* heap, int v, int dist) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->arr[i].vertex == v) {
            heap->arr[i].dist = dist;
            while (i != 0 && heap->arr[(i-1)/2].dist > heap->arr[i].dist) {
                swap(&heap->arr[i], &heap->arr[(i-1)/2]);
                i = (i-1)/2;
            }
            break;
        }
    }
}

int isInHeap(struct Heap* heap, int v) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->arr[i].vertex == v) return 1;
    }
    return 0;
}

void dijkstra(struct Edge* adj[], int n, int src) {
    int dist[n+1];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct Heap heap;
    heap.size = n;
    heap.arr = (struct Node*)malloc(n * sizeof(struct Node));
    for (int i = 0; i < n; i++) {
        heap.arr[i].vertex = i+1;
        heap.arr[i].dist = dist[i+1];
    }

    while (heap.size > 0) {
        struct Node minNode = extractMin(&heap);
        int u = minNode.vertex;
        struct Edge* e = adj[u];
        while (e != NULL) {
            int v = e->v;
            int w = e->w;
            if (isInHeap(&heap, v) && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                decreaseKey(&heap, v, dist[v]);
            }
            e = e->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    free(heap.arr);
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
    //    adj[v] = addEdge(adj[v], u, w); 
    }

    int src;
    scanf("%d", &src);

    dijkstra(adj, n, src);

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
