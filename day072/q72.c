#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);

    int seen[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        int idx = s[i] - 'a';
        if (seen[idx]) {
            printf("First repeated character: %c\n", s[i]);
            return 0;
        }
        seen[idx] = 1;
    }

    printf("-1\n");
    return 0;
}
