/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array
of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.

Solution:

Time Complexity: O(min(length(strs)))
Space Complexity: O(1)

*/

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int numStrings = strs.size();
        string prefix = "";

        // Early stopping
        if (numStrings == 0)
        {
            return prefix;
        }

        int pos = 0;
        bool end = false;
        while (!end)
        {
            if (pos >= strs[0].length())
            {
                break;
            }

            for (int i = 1; i < numStrings; i++)
            {
                if ((pos >= strs[i].length()) || (strs[i][pos] != strs[0][pos]))
                {
                    end = true;
                    break;
                }
            }

            if (!end)
            {
                prefix += strs[0][pos];
                pos++;
            }
        }

        return prefix;
    }
};