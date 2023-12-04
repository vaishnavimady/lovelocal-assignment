#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;  // Variable to store the length of the last word
    int i = strlen(s) - 1; //Starting from the last character of the string

 // Calculating the length of the last word by counting characters until a space or the start of the string
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;  //Returning the length of the last word
}

int main() {
    char input[] = "Hello World"; // Input string
    int result = lengthOfLastWord(input); // Calling the function to find the length of the last word
    printf("Length of last word: %d\n", result); // Printing the length of the last word
    return 0; // Return 0 to indicate successful execution
}
