#include <stdio.h>
#include <stdbool.h>
#include "../solutions/solution.c"
// Function to find the missing number

// Function to run one test case
void runTestCase(int* nums, int n, int expected, int* passedCount, int* total) {
    int result = missingNumber(nums, n);
    int i= 0;
    if (result == expected) {
        printf("? Test %d Passed\n", (*total) + 1);
        (*passedCount)++;
    } else {
        printf("? Test Failed for input: ");
        for (i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\nExpected: %d, Actual: %d\n", expected, result);
    }
    (*total)++;
}

// Main function
int main() {
    int passedCount = 0, total = 0;

    // Test 1
    int nums1[] = {3, 0, 1};
    runTestCase(nums1, 3, 2, &passedCount, &total);

    // Test 2
    int nums2[] = {0, 1};
    runTestCase(nums2, 2, 2, &passedCount, &total);

    // Test 3
    int nums3[] = {9,6,4,2,3,5,7,0,1};
    runTestCase(nums3, 9, 8, &passedCount, &total);

    // Test 4
    int nums4[] = {0};
    runTestCase(nums4, 1, 1, &passedCount, &total);

    // Test 5
    int nums5[] = {1};
    runTestCase(nums5, 1, 0, &passedCount, &total);

    // Test 6
    int nums6[] = {1, 2};
    runTestCase(nums6, 2, 0, &passedCount, &total);

    // ? Fixed Large Case (missing 57 from 0 to 99)
    int large[99];
    int idx = 0, i=0;
    for (i = 0; i <= 99; i++) {
        if (i != 57) {
            large[idx++] = i;
        }
    }
    runTestCase(large, 99, 57, &passedCount, &total);

    // Summary
    printf("\nPassed %d / %d test cases!\n", passedCount, total);
    return 0;
}

