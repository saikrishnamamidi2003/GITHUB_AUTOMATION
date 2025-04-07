package tests;

import solutions.Solution;
import java.util.Arrays;

public class Test {
    private static int passed = 0;
    private static int total = 0;

    public static void runTestCase(int[] input, int expected) {
        total++;
        int actual = Solution.missingNumber(input);

        if (actual == expected) {
            passed++;
            System.out.println("✅ Test Passed");
        } else {
            System.out.println("❌ Test Failed for input: " + Arrays.toString(input));
            System.out.println("   Expected: " + expected);
            System.out.println("   Actual  : " + actual);
        }
    }

    public static void main(String[] args) {
        // ✅ Basic test cases
        runTestCase(new int[]{3, 0, 1}, 2);
        runTestCase(new int[]{0, 1}, 2);
        runTestCase(new int[]{9, 6, 4, 2, 3, 5, 7, 0, 1}, 8);
        runTestCase(new int[]{0}, 1);

        // ✅ Edge cases
        runTestCase(new int[]{}, 0);
        runTestCase(new int[]{1}, 0);
        runTestCase(new int[]{0, 2}, 1);

        // ✅ Large test case
        int n = 100000;
        int[] large = new int[n];
        for (int i = 0; i < n; i++) large[i] = i;
        large[12345] = n; // Simulate missing number
        runTestCase(Arrays.copyOf(large, n), 12345);

        // ✅ Summary
        System.out.printf("\n✅ Passed %d / %d test cases!\n", passed, total);
        if (passed != total) {
            throw new AssertionError("Some test cases failed!");
        }
    }
}
