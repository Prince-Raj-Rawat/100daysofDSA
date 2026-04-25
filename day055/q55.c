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

void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int count = rear - front;
        for (int i = 0; i < count; i++) {
            struct Node* node = queue[front++];
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;

            if (i == count - 1) {
                printf("%d ", node->data);
            }
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

    printf("\nRight View of the Binary Tree:\n");
    rightView(root);
    printf("\n");

    freeTree(root);
    return 0;
}
