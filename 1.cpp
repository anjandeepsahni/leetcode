/*

1. Two Sum

Given an array of integers, return indices of the two numbers such that they
add up to a specific target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result{-1, -1};
        unordered_map<int, int> numsMap;

        // Validate inputs
        if (nums.size() < 2)
        {
            return result;
        }

        // Loop over all numbers and insert in hashmap
        for (int i = 0; i < nums.size(); i++)
        {
            int curNum = nums[i];
            int complement = target - curNum;
            if (numsMap.find(complement) == numsMap.end())
            {
                // Complement not in hashmap, insert current num
                numsMap[curNum] = i;
            }
            else
            {
                // If complement is already in hashmap, found pair.
                result[0] = i;
                result[1] = numsMap[complement];
                break;
            }
        }

        return result;
    }
};