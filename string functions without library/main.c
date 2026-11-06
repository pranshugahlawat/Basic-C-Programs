#include <stdio.h>

int my_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void my_strcpy(char dest[], char src[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

void my_strcat(char dest[], char src[]) {
    int i = my_strlen(dest), j = 0;
    while ((dest[i++] = src[j++]) != '\0');
}

int my_strcmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') return 0;
        i++;
    }
    return s1[i] - s2[i];
}

int main() {
    char s1[100], s2[100], copy[100];
    printf("Enter String 1: ");
    scanf("%s", s1);
    printf("Enter String 2: ");
    scanf("%s", s2);
    printf("Length of String 1: %d\n", my_strlen(s1));
    my_strcpy(copy, s1);
    printf("Copied String 1 into new array: %s\n", copy);
    if (my_strcmp(s1, s2) == 0) printf("Strings are Equal.\n");
    else printf("Strings are Not Equal.\n");
    my_strcat(s1, s2);
    printf("Concatenated String: %s\n", s1);
    return 0;
}