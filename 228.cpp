/*

228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the
array exactly. That is, each element of nums is covered by exactly one of the
ranges, and there is no integer x such that x is in one of the ranges but not in
nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Constraints:

- 0 <= nums.length <= 20
- -231 <= nums[i] <= 231 - 1
- All the values of nums are unique.
- nums is sorted in ascending order.

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }

        // Add the starting range.

        int prevIdx = 0;
        vector<string> ranges;
        string currentRange = to_string(nums.front());

        for (int i = 1; i <= nums.size(); ++i)
        {
            if (i == nums.size() || nums.at(i) - 1 > nums.at(i - 1))
            {
                // Break the range.
                if (prevIdx != i - 1)
                {
                    currentRange += ("->" + to_string(nums.at(i - 1)));
                }
                ranges.push_back(currentRange);
                if (i != nums.size())
                {
                    currentRange = to_string(nums.at(i));
                    prevIdx = i;
                }
            }
        }

        return ranges;
    }
};
