#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    Interval *x = (Interval*)a;
    Interval *y = (Interval*)b;
    return x->start - y->start;
}

Interval* mergeIntervals(Interval arr[], int n, int *returnSize) {
    qsort(arr, n, sizeof(Interval), cmpStart);
    Interval *result = (Interval*)malloc(n * sizeof(Interval));
    int idx = 0;
    result[idx] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            if (arr[i].end > result[idx].end) result[idx].end = arr[i].end;
        } else {
            idx++;
            result[idx] = arr[i];
        }
    }
    *returnSize = idx + 1;
    return result;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval *arr = (Interval*)malloc(n * sizeof(Interval));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].start, &arr[i].end);

    int returnSize;
    Interval *merged = mergeIntervals(arr, n, &returnSize);

    printf("Merged intervals: ");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d] ", merged[i].start, merged[i].end);
    }
    printf("\n");

    free(arr);
    free(merged);
    return 0;
}
