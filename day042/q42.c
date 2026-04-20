#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    Node* top;
} Stack;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void enqueue(Queue* q, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void push(Stack* s, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = s->top;
    s->top = node;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;
    Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

void reverseQueue(Queue* q) {
    Stack* s = createStack();
    while (q->front != NULL) {
        push(s, dequeue(q));
    }
    while (s->top != NULL) {
        enqueue(q, pop(s));
    }
    free(s);
}

void displayQueue(Queue* q) {
    Node* curr = q->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    int N, x;
    scanf("%d", &N);
    Queue* q = createQueue();
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }
    reverseQueue(q);
    displayQueue(q);
    freeQueue(q);
    return 0;
}
