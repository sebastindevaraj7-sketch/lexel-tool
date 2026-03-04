#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char productions[10][10];
char first[10], follow[10];
int m = 0;

void findFirst(char c);
void findFollow(char c);

int main() {
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("Enter non-terminal to find FIRST and FOLLOW: ");
    scanf(" %c", &c);

    printf("\nFIRST(%c) = { ", c);
    findFirst(c);
    printf("}\n");

    m = 0;
    printf("FOLLOW(%c) = { ", c);
    findFollow(c);
    printf("}\n");

    return 0;
}

void findFirst(char c) {
    int i, j;

    if (!isupper(c)) {
        printf("%c ", c);
        return;
    }

    for (i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            if (!isupper(productions[i][2])) {
                printf("%c ", productions[i][2]);
            } else {
                findFirst(productions[i][2]);
            }
        }
    }
}

void findFollow(char c) {
    int i, j;

    if (productions[0][0] == c)
        printf("$ ");

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == c) {
                if (productions[i][j+1] != '\0')
                    findFirst(productions[i][j+1]);
                if (productions[i][j+1] == '\0' && c != productions[i][0])
                    findFollow(productions[i][0]);
            }
        }
    }
}
