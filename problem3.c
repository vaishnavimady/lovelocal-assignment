#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* shortestPalindrome(char* s) {
    int n = strlen(s), i = 0, j = n - 1;

    while (j >= 0) {
        if (s[i] == s[j]) {
            i++;
        }
        j--;
    }

    if (i == n) {
        return s;
    }

    reverseString(s, i, n - 1);

    char* result = (char*)malloc(sizeof(char) * (2 * n - i + 1));
    strcpy(result, s + i);
    strncat(result, s, i);
    return result;
}

int main() {
    char input[] = "aacecaaa";
    char* result = shortestPalindrome(input);
    printf("Shortest palindrome: %s\n", result);
    free(result);
    return 0;
}
