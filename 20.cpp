/*

20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true

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
    bool isValid(string s)
    {
        vector<char> stack;
        for (auto& ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push_back(ch);
            }
            else
            {
                if ((stack.size() > 0) && ((ch == ')' && stack.back() == '(') ||
                                           (ch == '}' && stack.back() == '{') ||
                                           (ch == ']' && stack.back() == '[')))
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        return (stack.size() == 0);
    }
};