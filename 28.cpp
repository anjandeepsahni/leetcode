/*

28. Implement strStr()

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty
string. This is consistent to C's strstr() and Java's indexOf().

Solution:

Time Complexity: O(nm) // Not sure
Space Complexity: O(1)

*/

#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "" || haystack == needle)
        {
            return 0;
        }

        if (haystack.size() < needle.size())
        {
            return -1;
        }

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            // check if first char matches
            if (needle[0] == haystack[i])
            {
                int end = i + needle.size() - 1;
                if (end > haystack.size() - 1)
                {
                    return -1;
                }

                bool match = true;
                // try searching from needle end
                for (int j = needle.size() - 1; j > 0; j--)
                {
                    if (needle[j] != haystack[end])
                    {
                        match = false;
                        break;
                    }
                    end--;
                }
                if (match)
                {
                    return i;
                }
            }
        }

        return -1;
    }
};