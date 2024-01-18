/*

118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

Constraints: 1 <= numRows <= 30

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal;
        if (numRows <= 0)
        {
            return pascal;  // Early return.
        }

        // First row.
        pascal.push_back({1});

        for (int i = 1; i < numRows; ++i)
        {
            const vector<int>& prevRow = pascal.at(i - 1);
            vector<int> row = {1};
            for (int j = 1; j < i; ++j)
            {
                row.push_back(prevRow.at(j - 1) + prevRow.at(j));
            }
            row.push_back(1);
            pascal.push_back(row);
        }

        return pascal;
    }
};
