package solutions;
public class Solution {
    // ✅ Efficient solution using sum formula to find the missing number
    public static int missingNumber(int[] nums) {
        long n = nums.length;
        long expectedSum = n * (n + 1) / 2;
        long actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return (int)(expectedSum - actualSum);
    }
}
