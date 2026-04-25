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

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end) return NULL;

    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];
    printf("Enter %d values for preorder traversal:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);

    printf("Enter %d values for inorder traversal:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("\nPostorder traversal of constructed tree:\n");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
