#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct HeapNode** array;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = heap->array[smallest];
        struct HeapNode* idxNode = heap->array[idx];
        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;
        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;
    struct HeapNode* root = heap->array[0];
    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;
    while (i && heap->array[i]->dist < heap->array[(i-1)/2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i-1)/2;
        heap->pos[heap->array[(i-1)/2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

int isInMinHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INT_MAX;

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[src] = 0;
    heap->array[src]->dist = 0;
    heap->size = V;

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
        free(minNode);
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("%d -> INF\n", i);
        else printf("%d -> %d\n", i, dist[i]);
    }

    for (int i = 0; i < heap->capacity; i++) free(heap->array[i]);
    free(heap->array);
    free(heap->pos);
    free(heap);
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adj);
    free(graph);
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Graph* graph = createGraph(n);

    printf("Enter %d edges (src dest weight):\n", e);
    for (int i = 0; i < e; i++) {
        int src, dest, w;
        scanf("%d %d %d", &src, &dest, &w);
        addEdge(graph, src, dest, w);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    dijkstra(graph, s);

    freeGraph(graph);
    return 0;
}
