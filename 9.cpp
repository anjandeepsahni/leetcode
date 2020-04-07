/*

9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when
it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Coud you solve it without converting the integer to a string?

Solution:

Time Complexity: O(log n)
Space Complexity: O(1)

*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // All negative numbers are non-palindrome.
        // If last digit = 0, then palindrome only if x=0.
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int rev = 0;
        // Reverse half the number.
        while (x > rev)
        {
            int remainder = x % 10;
            rev = rev * 10 + remainder;
            x = x / 10;
        }
        return x == rev || x == rev / 10;
    }
};