#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n, int index) {
    if (index >= n || arr[index] == -1) return NULL;
    struct Node* root = createNode(arr[index]);
    root->left = buildTree(arr, n, 2*index + 1);
    root->right = buildTree(arr, n, 2*index + 2);
    return root;
}

void findMinMax(struct Node* root, int hd, int *min, int *max) {
    if (root == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, hd-1, min, max);
    findMinMax(root->right, hd+1, min, max);
}

void printVerticalLine(struct Node* root, int line, int hd) {
    if (root == NULL) return;
    if (hd == line) printf("%d ", root->data);
    printVerticalLine(root->left, line, hd-1);
    printVerticalLine(root->right, line, hd+1);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("Enter number of nodes (including -1 for NULLs): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d space-separated values (use -1 for NULL):\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int min = 0, max = 0;
    findMinMax(root, 0, &min, &max);

    printf("\nVertical Order Traversal:\n");
    for (int line = min; line <= max; line++) {
        printVerticalLine(root, line, 0);
        printf("\n");
    }

    freeTree(root);
    return 0;
}
