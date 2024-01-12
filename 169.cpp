/*

169. Majority Element

Given an array nums of size n, return the majority element. The majority element
is the element that appears more than ⌊n / 2⌋ times. You may assume that the
majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

Follow-up: Could you solve the problem in linear time and in O(1) space?

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int element = nums.at(0);
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            element = (counter == 0) ? nums.at(i) : element;
            counter = (nums.at(i) == element) ? counter + 1 : counter - 1;
        }

        return element;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1
    vector<int> nums{3, 2, 3};
    assert(solution.majorityElement(nums) == 3);

    // Testcase 2
    vector<int> nums2{2, 2, 1, 1, 1, 2, 2};
    assert(solution.majorityElement(nums2) == 2);

    cout << "Tests PASSED" << endl;
}