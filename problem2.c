#include <stdio.h>

void findMajorityElements(int nums[], int n) {
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
        else if (count1 == 0) {
            num1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            num2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }

    if (count1 > n / 3)
        printf("%d ", num1);
    if (count2 > n / 3)
        printf("%d ", num2);
}

int main() {
    int nums[] = {3, 2, 3, 2, 2, 3, 1, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Elements appearing more than n/3 times: ");
    findMajorityElements(nums, size);
    
    return 0;
}
