#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return 0;
        if (sum + books[i] > maxPages) {
            students++;
            sum = books[i];
            if (students > m) return 0;
        } else {
            sum += books[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int *books = (int *)malloc(n * sizeof(int));
    if (books == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) scanf("%d", &books[i]);

    int low = 0, high = 0, ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (books[i] > low) low = books[i];
        high += books[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Minimum possible maximum pages: %d\n", ans);

    free(books);
    return 0;
}
