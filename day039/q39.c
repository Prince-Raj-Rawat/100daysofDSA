#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin() {
    if (size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
    return root;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1.Insert 2.Peek 3.ExtractMin 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                printf("%d\n", peek());
                break;
            case 3:
                printf("%d\n", extractMin());
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
