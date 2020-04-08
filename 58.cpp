/*

58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word (last word means the last
appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space
characters only.

Example:

Input: "Hello World"
Output: 5

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        bool foundSpace = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                foundSpace = true;
                continue;
            }
            else
            {
                if (foundSpace)
                {
                    foundSpace = false;
                    length = 1;
                }
                else
                    length++;
            }
        }
        return length;
    }
};