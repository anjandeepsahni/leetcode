/*

Given the root of a binary tree, return the inorder traversal of its nodes'
values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?

Solution:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> stack;
        vector<int> result;

        TreeNode* curNode = root;
        while (!(curNode == nullptr && stack.size() == 0))
        {
            if (curNode != nullptr)
            {
                // Step 1. Keep going left until we reach nullptr node
                stack.push_back(curNode);
                curNode = curNode->left;
            }
            else
            {
                // Step 2. Left most node is in stack, pop and add to result
                TreeNode* node = stack.back();
                stack.pop_back();
                result.push_back(node->val);
                curNode = node->right;
            }
        }

        return result;
    }
};