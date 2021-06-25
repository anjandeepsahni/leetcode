/*

35. Search Insert Position

Given a sorted array and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 4:

Input: [1,3,5,6], 0
Output: 0

Solution:

Time Complexity: O(nm) // Not sure
Space Complexity: O(1)

*/

#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int pos = nums.size();

        while (start <= end)
        {
            int mid = (end + start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
                pos = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return pos;
    }
};