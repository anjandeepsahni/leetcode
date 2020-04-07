/*

7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:

Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
this problem, assume that your function returns 0 when the reversed integer
overflows.

Solution:

Time Complexity: O(log x)
Space Complexity: O(1)

*/

#include <limits.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x)
        {
            int remainder = x % 10;
            // Check for overflow.
            // If reverse == Integer.MAX_VALUE/10, then reverse = 2,147,483,640.
            // We know that anything over 2,147,483,647 causes integer overflow,
            // so remainder cannot be greater than 7.
            // Likewise, if reverse == Integer.MIN_VALUE/10, then
            // reverse = -2,147,483,640. We know that anything under
            // -2,147,483,648 causes integer underflow, so remainder cannot be
            // less than -8.
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && remainder > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && remainder < -8))
                return 0;
            rev = rev * 10 + remainder;
            x = x / 10;
        }
        return rev;
    }
};