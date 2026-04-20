#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int count;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->count = 0;
    return dq;
}

void push_front(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->prev = NULL;
    node->next = dq->front;
    if (dq->front) dq->front->prev = node;
    dq->front = node;
    if (!dq->rear) dq->rear = node;
    dq->count++;
}

void push_back(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = dq->rear;
    if (dq->rear) dq->rear->next = node;
    dq->rear = node;
    if (!dq->front) dq->front = node;
    dq->count++;
}

void pop_front(Deque* dq) {
    if (!dq->front) return;
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if (!dq->rear) return;
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->count--;
}

int front(Deque* dq) {
    if (!dq->front) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (!dq->rear) return -1;
    return dq->rear->data;
}

int empty(Deque* dq) {
    return dq->count == 0;
}

int size(Deque* dq) {
    return dq->count;
}

void clear(Deque* dq) {
    while (!empty(dq)) pop_front(dq);
}

void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}

void printDeque(Deque* dq) {
    Node* curr = dq->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();
    push_back(dq, 10);
    push_front(dq, 20);
    push_back(dq, 30);
    printDeque(dq);
    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    pop_front(dq);
    pop_back(dq);
    printDeque(dq);
    reverse(dq);
    printDeque(dq);
    clear(dq);
    printf("Size after clear: %d\n", size(dq));
    return 0;
}
