#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] <= h->data[i]) break;
        swap(&h->data[p], &h->data[i]);
        i = p;
    }
}

void heapifyDown(MinHeap *h, int i) {
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < h->size && h->data[l] < h->data[smallest]) smallest = l;
        if (r < h->size && h->data[r] < h->data[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
}

void push(MinHeap *h, int val) {
    h->data[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int pop(MinHeap *h) {
    int root = h->data[0];
    h->data[0] = h->data[--h->size];
    heapifyDown(h, 0);
    return root;
}

int top(MinHeap *h) {
    return h->data[0];
}

int minMeetingRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), cmpStart);
    MinHeap *h = createHeap(n);
    push(h, arr[0].end);
    int rooms = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= top(h)) pop(h);
        push(h, arr[i].end);
        if (h->size > rooms) rooms = h->size;
    }
    free(h->data);
    free(h);
    return rooms;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    Interval *arr = (Interval*)malloc(n * sizeof(Interval));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter start and end times of meetings:\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].start, &arr[i].end);

    int result = minMeetingRooms(arr, n);
    printf("Minimum number of rooms required: %d\n", result);

    free(arr);
    return 0;
}
