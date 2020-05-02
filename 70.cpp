/*

70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int two_step_back = 1; // number of ways for n=1
        int one_step_back = 2; // number of ways for n=2
        int current = 0;
        for (int i = 3; i <= n; i++)
        {
            current = one_step_back + two_step_back;
            two_step_back = one_step_back;
            one_step_back = current;
        }
        return current;
    }
};