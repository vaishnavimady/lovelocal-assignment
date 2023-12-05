#include <stdio.h>

int countDigitOne(int n) {
    int count = 0;

    // Loop through each digit place (ones, tens, hundreds, etc.)
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;

        // Calculate count of 1s contributed by the current digit place
        count += (n / divider) * i + fmin(fmax(n % divider - i + 1, 0), i);
        // Explanation:
        // (n / divider) * i counts 1s contributed by higher digits
        // fmin(fmax(n % divider - i + 1, 0), i) counts 1s at the current digit place
        // fmax(n % divider - i + 1, 0) ensures that if the difference is negative, it's considered 0
    }

    return count; // Return the total count of digit 1 in the range from 0 to n
}

int main() {
    int n = 13; // Example input value
    int result = countDigitOne(n); // Calculate the count of digit 1
    printf("Total number of digit 1 from 0 to %d is %d\n", n, result); // Print the result
    return 0;
}
