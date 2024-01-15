/*

203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the
linked list that has Node.val == val, and return the new head.

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Constraints:

1. The number of nodes in the list is in the range [0, 104].
2. 1 <= Node.val <= 50
3. 0 <= val <= 50

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* curNode = head;
        ListNode* prevNode = nullptr;

        while (curNode != nullptr)
        {
            if (curNode->val == val)
            {
                // Remove this node.
                if (prevNode == nullptr)
                {
                    // No previous node, move the head to the next node.
                    head = curNode->next;
                }
                else
                {
                    prevNode->next = curNode->next;
                }
            }
            else
            {
                prevNode = curNode;
            }

            curNode = curNode->next;
        }

        return head;
    }
};