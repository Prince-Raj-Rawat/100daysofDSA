#include <stdio.h>
#include <stdlib.h>

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

void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* currentLevel[1000];
    struct Node* nextLevel[1000];
    int currentTop = 0, nextTop = 0;
    int leftToRight = 1;

    currentLevel[currentTop++] = root;

    while (currentTop > 0) {
        struct Node* node = currentLevel[--currentTop];
        printf("%d ", node->data);

        if (leftToRight) {
            if (node->left) nextLevel[nextTop++] = node->left;
            if (node->right) nextLevel[nextTop++] = node->right;
        } else {
            if (node->right) nextLevel[nextTop++] = node->right;
            if (node->left) nextLevel[nextTop++] = node->left;
        }

        if (currentTop == 0) {
            leftToRight = !leftToRight;
            for (int i = 0; i < nextTop; i++) {
                currentLevel[i] = nextLevel[i];
            }
            currentTop = nextTop;
            nextTop = 0;
        }
    }
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

    printf("\nZigzag (Spiral) Level Order Traversal:\n");
    zigzagTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}
