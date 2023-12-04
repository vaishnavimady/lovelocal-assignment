#include <stdio.h>

void findMajorityElements(int nums[], int n) {
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0; // Initializing variables to store potential majority elements and their counts
    
    // Looping through the array to find potential majority elements
    for (int i = 0; i < n; i++) {
        if (nums[i] == num1)
            count1++;       // Increment count for num1 if the current element matches num1
        else if (nums[i] == num2)
            count2++;       // Increment count for num2 if the current element matches num2
        else if (count1 == 0) {
            num1 = nums[i]; // If count1 is 0, assign the current element as num1
            count1 = 1;
        } else if (count2 == 0) {
            num2 = nums[i]; // If count2 is 0, assign the current element as num2
            count2 = 1;
        } else {
            count1--;       // Decrementing counts when neither num1 nor num2 matches the current element
            count2--;
        }
    }

    count1 = count2 = 0;

    // Counting occurrences of majority elements in the array
    for (int i = 0; i < n; i++) {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }

    // Checking if counts of majority elements are more than n/3 and printing them
    if (count1 > n / 3)
        printf("%d ", num1);
    if (count2 > n / 3)
        printf("%d ", num2);
}

int main() {
    int nums[] = {3, 2, 3, 2, 2, 3, 1, 1};
    int size = sizeof(nums) / sizeof(nums[0]); // Calculating the size of the array

    printf("Elements appearing more than n/3 times: ");
    findMajorityElements(nums, size); // Calling function to find majority elements
    
    return 0;
}
