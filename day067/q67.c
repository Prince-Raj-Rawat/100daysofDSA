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

void dfs(struct Graph* graph, int v, int visited[], int* stack, int* top) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u]) dfs(graph, u, visited, stack, top);
        temp = temp->next;
    }
    stack[(*top)++] = v;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) dfs(graph, i, visited, stack, &top);
    }

    printf("Topological Ordering:\n");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
    free(stack);
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

    topologicalSort(graph);

    freeGraph(graph);
    return 0;
}
