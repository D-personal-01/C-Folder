#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char word[20];
    char smallest[20] = "";
    char largest[20] = "";

    int i = 0, j = 0;

    printf("Enter a string: ");
    str[]="hello every one my name is thebestinthe world";   // Safe input

    while (1) {
        // If space or end of string is found
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
            word[j] = '\0';   // End current word

            if (j > 0) {      // Ignore empty words
                if (smallest[0] == '\0' || strlen(word) < strlen(smallest))
                    strcpy(smallest, word);

                if (largest[0] == '\0' || strlen(word) > strlen(largest))
                    strcpy(largest, word);
            }
            j = 0;  // Reset for next word
        }
        else {
            word[j++] = str[i];
        }

        if (str[i] == '\0' || str[i] == '\n')
            break;

        i++;
    }

    printf("Smallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}
