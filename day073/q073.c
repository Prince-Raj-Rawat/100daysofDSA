#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);

    int freq[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");
    return 0;
}
