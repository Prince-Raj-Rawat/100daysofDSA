#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char temp[100];
    struct Candidate *list = (struct Candidate*)malloc(n * sizeof(struct Candidate));
    int count = 0;

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(list[j].name, temp) == 0) {
                list[j].votes++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(list[count].name, temp);
            list[count].votes = 1;
            count++;
        }
    }

    char winner[100];
    int maxVotes = -1;
    for (int i = 0; i < count; i++) {
        if (list[i].votes > maxVotes) {
            maxVotes = list[i].votes;
            strcpy(winner, list[i].name);
        } else if (list[i].votes == maxVotes && strcmp(list[i].name, winner) < 0) {
            strcpy(winner, list[i].name);
        }
    }

    printf("Winner: %s with %d votes\n", winner, maxVotes);

    free(list);
    return 0;
}
