#include <stdio.h>
#include <string.h>

int main() {
    char production[20], alpha[20], beta[20];
    char nonTerminal;
    int i = 0, j = 0;

    printf("Enter Production (Example: E=E+T/T): ");
    scanf("%s", production);

    nonTerminal = production[0];

    if (production[2] == nonTerminal) {
        // Left Recursion exists
        for (i = 3; production[i] != '/'; i++)
            alpha[j++] = production[i];
        alpha[j] = '\0';

        j = 0;
        for (i = i + 1; production[i] != '\0'; i++)
            beta[j++] = production[i];
        beta[j] = '\0';

        printf("\nGrammar after eliminating Left Recursion:\n");
        printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
        printf("%c' -> %s%c' | ε\n", nonTerminal, alpha, nonTerminal);
    } else {
        printf("\nNo Left Recursion detected.\n");
    }

    return 0;
}
