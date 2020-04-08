/*

53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using
the divide and conquer approach, which is more subtle.

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int maxSum = nums[0];
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = max(nums[i], temp + nums[i]);
            maxSum = max(temp, maxSum);
        }
        return maxSum;
    }
};