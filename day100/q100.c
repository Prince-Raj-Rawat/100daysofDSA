#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

long long merge(Pair arr[], int l, int m, int r, int *count) {
    int n1 = m - l + 1, n2 = r - m;
    Pair *L = (Pair*)malloc(n1 * sizeof(Pair));
    Pair *R = (Pair*)malloc(n2 * sizeof(Pair));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += j; // j elements from right are smaller
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i);
        }
    }
    while (i < n1) {
        count[L[i].idx] += j;
        arr[k++] = L[i++];
    }
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
    return invCount;
}

long long mergeSort(Pair arr[], int l, int r, int *count) {
    long long invCount = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        invCount += mergeSort(arr, l, m, count);
        invCount += mergeSort(arr, m + 1, r, count);
        invCount += merge(arr, l, m, r, count);
    }
    return invCount;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    Pair *arr = (Pair*)malloc(n * sizeof(Pair));
    int *count = (int*)calloc(n, sizeof(int));
    if (nums == NULL || arr == NULL || count == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Counts of smaller elements to right:\n");
    for (int i = 0; i < n; i++) printf("%d ", count[i]);
    printf("\n");

    free(nums);
    free(arr);
    free(count);
    return 0;
}
