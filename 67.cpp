/*

67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string sum = "";
        int carry = 0;
        auto ptrA = a.rbegin();
        auto ptrB = b.rbegin();
        for (int i = 0; i < max(a.size(), b.size()); ++i)
        {
            int chA = i < a.size() ? *(ptrA + i) - '0' : 0;
            int chB = i < b.size() ? *(ptrB + i) - '0' : 0;
            int res = (chA + chB + carry) % 2;
            carry = (chA + chB + carry) / 2;
            sum.push_back(res + '0');
        }
        if (carry > 0)
            sum.push_back(carry + '0');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};