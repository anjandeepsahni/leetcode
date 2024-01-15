/*

168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it
appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:

Input: columnNumber = 1
Output: "A"

Example 2:

Input: columnNumber = 28
Output: "AB"

Example 3:

Input: columnNumber = 701
Output: "ZY"

Constraints: 1 <= columnNumber <= 2^31 - 1

Solution:

Time Complexity: O(log_26 N)
Space Complexity: O(1) // except to store the string

*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        const int N = 26;
        string columnName = "";

        while (columnNumber > 0)
        {
            const int rem = columnNumber % N;
            char remChar;
            if (rem == 0)
            {
                remChar = 'Z';
                columnNumber = columnNumber / N - 1;
            }
            else
            {
                remChar = 'A' + rem - 1;
                columnNumber = columnNumber / N;
            }
            columnName = remChar + columnName;
        }

        return columnName;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1
    assert(solution.convertToTitle(1) == "A");

    // Testcase 2
    assert(solution.convertToTitle(28) == "AB");

    // Testcase 3
    assert(solution.convertToTitle(701) == "ZY");

    cout << "Tests PASSED" << endl;
}