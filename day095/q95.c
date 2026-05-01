#include <stdio.h>
#include <stdlib.h>

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(double arr[], int n) {
    double **buckets = (double **)malloc(n * sizeof(double *));
    int *sizes = (int *)calloc(n, sizeof(int));
    int *capacity = (int *)malloc(n * sizeof(int));

    if (buckets == NULL || sizes == NULL || capacity == NULL) {
        printf("Memory allocation failed\n");
        free(buckets);
        free(sizes);
        free(capacity);
        return;
    }

    for (int i = 0; i < n; i++) {
        capacity[i] = 2;
        buckets[i] = (double *)malloc(capacity[i] * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        if (sizes[idx] == capacity[idx]) {
            capacity[idx] *= 2;
            buckets[idx] = (double *)realloc(buckets[idx], capacity[idx] * sizeof(double));
        }
        buckets[idx][sizes[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (sizes[i] > 1) insertionSort(buckets[i], sizes[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(sizes);
    free(capacity);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter real numbers in [0,1): ");
    for (int i = 0; i < n; i++) scanf("%lf", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%lf ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

