#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
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

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

int dfsCycle(struct Graph* graph, int v, int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u] && dfsCycle(graph, u, visited, recStack)) return 1;
        else if (recStack[u]) return 1;
        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* recStack = (int*)calloc(graph->V, sizeof(int));
    int cycle = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    free(visited);
    free(recStack);
    return cycle;
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

    printf("Enter %d edges (src dest):\n", e);
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    if (hasCycle(graph)) printf("YES\n");
    else printf("NO\n");

    freeGraph(graph);
    return 0;
}
