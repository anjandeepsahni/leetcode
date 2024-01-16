/*

206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the
reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
1. The number of nodes in the list is the range [0, 5000].
2. -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively.
Could you implement both?

Solution:

Time Complexity: O(n)
Space Complexity: O(1)

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

class SolutionIterative
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head)
        {
            return head;
        }

        ListNode* curNode = head;
        ListNode* prevNode = nullptr;

        while (curNode)
        {
            head = curNode;
            ListNode* nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }

        return head;
    }
};

class SolutionRecursive
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* head2 = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return head2;
    }
};
