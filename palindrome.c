#include <stdio.h>
#include <string.h>

int main() {
    char str[50], rev[50];

    printf("Enter a word: ");
    scanf("%s", str);

    strcpy(rev, str);
    strrev(rev);

    if (strcmp(str, rev) == 0)
        printf("The word is a palindrome.");
    else
        printf("The word is not a palindrome.");

    return 0;
}