/*

191. Number of 1 Bits

Write a function that takes the binary representation of an unsigned integer and
returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input 00000000000000000000000000001011 has a total of three '1'
bits.

Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input 00000000000000000000000010000000 has a total of one '1'
bit.

Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input 11111111111111111111111111111101 has a total of thirty
one '1' bits.

Constraints: The input must be a uint32 number.

Follow up: If this function is called many times, how would you optimize it?
*/

#include <cassert>
#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int weight = 0;
        while (n > 0)
        {
            if ((n & 0x1) == 0x1)
            {
                ++weight;
            }

            n = n >> 1;
        }

        return weight;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1
    assert(solution.hammingWeight(0b00000000000000000000000000001011) == 3);

    // Testcase 2
    assert(solution.hammingWeight(0b00000000000000000000000010000000) == 1);

    // Testcase 3
    assert(solution.hammingWeight(0b11111111111111111111111111111101) == 31);

    cout << "Tests PASSED" << endl;
}