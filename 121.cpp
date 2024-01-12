/*

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on
the ith day. You want to maximize your profit by choosing a single day to buy
one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed
because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }

        size_t maxIndex{prices.size() - 1};
        int maxProfit{prices.back() - prices.at(prices.size() - 2)};

        for (int i = prices.size() - 3; i >= 0; --i)
        {
            maxIndex =
                (prices.at(maxIndex) > prices.at(i + 1)) ? maxIndex : i + 1;
            maxProfit = max(prices.at(maxIndex) - prices.at(i), maxProfit);
        }

        maxProfit = max(0, maxProfit);
        return maxProfit;
    }
};

int main()
{
    Solution solution{};

    // Testcase 1:
    vector<int> prices{7, 1, 5, 3, 6, 4};
    assert(solution.maxProfit(prices) == 5);

    // Testcase 2:
    vector<int> prices2{7, 6, 4, 3, 1};
    assert(solution.maxProfit(prices2) == 0);

    cout << "Tests PASSED!" << endl;
}