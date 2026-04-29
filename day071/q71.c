#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int *table;
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            printf("Inserted %d at position %d\n", key, pos);
            return;
        }
    }
    printf("Table overflow, could not insert %d\n", key);
}

int search(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (table[pos] == EMPTY) return 0;
        if (table[pos] == key) return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter table size: ");
    scanf("%d", &m);
    printf("Enter number of operations: ");
    scanf("%d", &n);

    table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    printf("\nAvailable operations:\n");
    printf("INSERT <key>\n");
    printf("SEARCH <key>\n\n");

    for (int i = 0; i < n; i++) {
        char op[10];
        int key;
        printf("Operation %d: ", i+1);
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key)) printf("Result: FOUND\n");
            else printf("Result: NOT FOUND\n");
        } else {
            printf("Invalid operation\n");
        }
    }

    free(table);
    return 0;
}
