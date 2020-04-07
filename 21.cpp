/*

21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should
be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // If either is nullptr, return the other list.
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != nullptr)
            cur->next = l1;
        else if (l2 != nullptr)
            cur->next = l2;

        return dummy.next;
    }
};