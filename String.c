#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Input size of string array:\n");
    scanf("%d", &n);

    char s[n][100]; // array of n strings, each up to 99 chars long

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);  // read each word (no spaces)
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", s[i]);
    }
    printf("\n");

    // Calculate number of strings in array
    int size = sizeof(s) / sizeof(s[0]);
    printf("Size of array = %d\n", size);

    return 0;
}
