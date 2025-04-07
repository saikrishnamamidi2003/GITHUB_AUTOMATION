#include <bits/stdc++.h>
#include "../solutions/solution.cpp"
using namespace std;

// Function to run individual test cases
void runTestCase(vector<int> arr, int expected, int *passedCount, int *total)
{
    (*total)++;
    Solution solution;
    int actual = solution.missingNumber(arr.data(), arr.size());

    if (actual == expected)
    {
        (*passedCount)++;
        cout << "\n✅ Test " << *total << " Passed";
    }
    else
    {
        cout << "\n❌ Test " << *total << " Failed for input: ";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << "\nExpected: " << expected << ", Actual: " << actual << endl;
    }
}

// Main function to run all test cases
int main()
{
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    runTestCase({3, 0, 1}, 2, &passedCount, &total);
    runTestCase({0, 1}, 2, &passedCount, &total);
    runTestCase({9, 6, 4, 2, 3, 5, 7, 0, 1}, 8, &passedCount, &total);
    runTestCase({0}, 1, &passedCount, &total);

    // ✅ Edge Cases
    runTestCase({}, 0, &passedCount, &total);           // Empty array
    runTestCase({1}, 0, &passedCount, &total);          // Missing 0
    runTestCase({0, 2}, 1, &passedCount, &total);       // Missing 1

    // ✅ Large Case
    vector<int> largeCase(100000);
    iota(largeCase.begin(), largeCase.end(), 0);
    largeCase[12345] = 100000; // Simulate missing number
    runTestCase(vector<int>(largeCase.begin(), largeCase.end()), 12345, &passedCount, &total);

    // ✅ Summary
    cout << "\n\nPassed " << passedCount << " / " << total << " test cases!" << endl;
    if (passedCount != total)
    {
        assert(false); // Fail fast in debug mode if any test fails
    }

    return 0;
}
