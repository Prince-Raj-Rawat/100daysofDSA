#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int l = 0, r = n, ans = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int l = 0, r = n, ans = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > x) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}
