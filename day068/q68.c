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

void topologicalSort(struct Graph* graph) {
    int* indegree = (int*)calloc(graph->V, sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    int count = 0;
    printf("Topological Ordering:\n");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = graph->adj[v];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) queue[rear++] = temp->vertex;
            temp = temp->next;
        }
    }
    printf("\n");

    if (count != graph->V) {
        printf("Graph is not a DAG (contains cycle)\n");
    }

    free(indegree);
    free(queue);
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
