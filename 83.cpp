/*

83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element
appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur)
        {
            if (cur->val == prev->val)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};