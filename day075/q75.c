#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define SIZE 1000

struct Node* hashTable[SIZE];

int hash(int sum) {
    if (sum < 0) sum = -sum;
    return sum % SIZE;
}

void insert(int sum, int index) {
    int h = hash(sum);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int search(int sum) {
    int h = hash(sum);
    struct Node* curr = hashTable[h];
    while (curr) {
        if (curr->sum == sum) return curr->index;
        curr = curr->next;
    }
    return -1;
}

void freeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* curr = hashTable[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int longestZeroSumSubarray(int arr[], int n) {
    for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;
    int maxLen = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }
        int prevIndex = search(sum);
        if (prevIndex != -1) {
            if (i - prevIndex > maxLen) maxLen = i - prevIndex;
        } else {
            insert(sum, i);
        }
    }
    freeHashTable();
    return maxLen;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = longestZeroSumSubarray(arr, n);
    printf("Length of longest subarray with sum 0: %d\n", result);
    return 0;
}
