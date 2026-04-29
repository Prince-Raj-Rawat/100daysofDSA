#include <stdio.h>

int intSqrt(int n) {
    if (n == 0 || n == 1) return n;
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;
        if (sq == n) return mid;
        if (sq < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", intSqrt(n));
    return 0;
}
