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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2) return findLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return findLCA(root->right, n1, n2);
    return root;
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);

    printf("Enter %d space-separated values:\n", n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int n1, n2;
    printf("Enter two node values to find their LCA: ");
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("Lowest Common Ancestor of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("One or both nodes not found in the BST.\n");
    }

    freeTree(root);
    return 0;
}
