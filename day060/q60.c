#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n, int index) {
    if (index >= n) return NULL;
    struct Node* root = createNode(arr[index]);
    root->left = buildTree(arr, n, 2*index + 1);
    root->right = buildTree(arr, n, 2*index + 2);
    return root;
}

int isMinHeap(struct Node* root) {
    if (root == NULL) return 1;
    if (root->left && root->data > root->left->data) return 0;
    if (root->right && root->data > root->right->data) return 0;
    return isMinHeap(root->left) && isMinHeap(root->right);
}

void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d space-separated values (level-order traversal):\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (isMinHeap(root)) printf("YES\n");
    else printf("NO\n");

    freeTree(root);
    return 0;
}
