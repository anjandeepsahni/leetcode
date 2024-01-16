/*

202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares
of its digits. Repeat the process until the number equals 1 (where it will
stay), or it loops endlessly in a cycle which does not include 1. Those numbers
for which this process ends in 1 are happy. Return true if n is a happy number,
and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

Constraints: 1 <= n <= 231 - 1

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    void getDigits(vector<int>& digits, int n)
    {
        const int base = 10;
        digits.clear();
        while (n >= base)
        {
            digits.push_back(n % base);
            n /= base;
        }
        digits.push_back(n);
    }

    int getSquare(const vector<int>& digits)
    {
        int square = 0;
        for (const auto& digit : digits)
        {
            square += (digit * digit);
        }
        return square;
    }

    bool isHappy(int n)
    {
        vector<int> digits{};
        unordered_map<int, int> nToSqMap{};

        while (nToSqMap.count(n) == 0)
        {
            getDigits(digits, n);
            const int sq = getSquare(digits);
            nToSqMap.insert({n, sq});
            n = sq;

            if (sq == 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1
    assert(solution.isHappy(19) == true);

    // Testcase 2
    assert(solution.isHappy(2) == false);

    cout << "Tests PASSED" << endl;
}