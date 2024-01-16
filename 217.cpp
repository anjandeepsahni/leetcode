/*

217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> uniqueNums{};
        for (const auto num : nums)
        {
            if (uniqueNums.count(num) >= 1)
            {
                return true;
            }
            uniqueNums.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1
    vector<int> tc1{1, 2, 3, 1};
    assert(solution.containsDuplicate(tc1) == true);

    // Testcase 2
    vector<int> tc2{1, 2, 3, 4};
    assert(solution.containsDuplicate(tc2) == false);

    // Testcase 3
    vector<int> tc3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    assert(solution.containsDuplicate(tc3) == true);

    cout << "Tests PASSED" << endl;
}