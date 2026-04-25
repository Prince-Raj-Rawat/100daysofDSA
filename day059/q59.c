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

struct Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    if (start > end) return NULL;
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;
    if (start == end) return root;
    int inIndex = search(inorder, start, end, root->data);
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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

    int inorder[n], postorder[n];
    printf("Enter %d values for inorder traversal:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    printf("Enter %d values for postorder traversal:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("\nPreorder traversal of constructed tree:\n");
    preorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
