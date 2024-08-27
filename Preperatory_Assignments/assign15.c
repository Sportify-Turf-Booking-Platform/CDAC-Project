//Input a string from the user. Count occurrences (case insensitive) of 
//each alphabet in the string.

#include <stdio.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

int main() {
    char str[100];
    int frequency[ALPHABET_COUNT] = {0};
    int i;

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Iterate over the string
    for (i = 0; str[i] != '\0'; i++) {
        char ch = toupper(str[i]);  // Convert to lowercase for case insensitivity
        if (ch >= 'A' && ch <= 'Z') {
            frequency[ch - 'A']++;
        }
    }

    // Display the occurrences of each alphabet
    printf("\nOccurrences of each alphabet:\n");
    for (i = 0; i < ALPHABET_COUNT; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", i + 'A', frequency[i]);
        }
    }

    return 0;
}
