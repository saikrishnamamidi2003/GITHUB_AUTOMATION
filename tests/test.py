import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))


from solutions.solution import Solution


def run_test_case(nums, expected, passed_count, total):
    total[0] += 1
    solution = Solution()  # Create an instance of Solution
    actual = solution.missingNumber(nums)  # Call the instance method

    if actual == expected:
        passed_count[0] += 1
        print(f"\n✅ {passed_count[0]}")
    else:
        print("\n❌ Test failed for input:", nums)
        print(f"Actual: {actual}, Expected: {expected}")

# ✅ Main function to run all test cases
def main():
    passed_count = [0]
    total = [0]

    # ✅ Basic Cases
    run_test_case([3, 0, 1], 2, passed_count, total)
    run_test_case([0, 1], 2, passed_count, total)
    run_test_case([9, 6, 4, 2, 3, 5, 7, 0, 1], 8, passed_count, total)
    run_test_case([0], 1, passed_count, total)
    run_test_case([], 0, passed_count, total)
    run_test_case([1], 0, passed_count, total)
    run_test_case([0, 2], 1, passed_count, total)

    # ✅ Large Case
    run_test_case(list(range(12345)) + list(range(12346, 12346 + 100)), 12345, passed_count, total)

    # ✅ Summary
    print(f"\nPassed {passed_count[0]} / {total[0]} test cases!")
    if passed_count[0] != total[0]:
        raise AssertionError("Some test cases failed!")

if __name__ == "_main_":
    main()