#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isPossible(int boards[], int n, int k, int maxLen) {
    int painters = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > maxLen) return 0;
        if (sum + boards[i] > maxLen) {
            painters++;
            sum = boards[i];
            if (painters > k) return 0;
        } else {
            sum += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int *boards = (int *)malloc(n * sizeof(int));
    if (boards == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter lengths of boards: ");
    for (int i = 0; i < n; i++) scanf("%d", &boards[i]);

    int low = 0, high = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Minimum time required: %d\n", ans);

    free(boards);
    return 0;
}
