#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//leetcode =>swap nodes note the values 
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        ListNode *first = new ListNode(0);
        first->next = head;

        ListNode *point = first;

        while (point->next != nullptr && point->next->next != nullptr)
        {
            // Identify nodes to swap
            ListNode *p1 = point->next;
            ListNode *p2 = point->next->next;

            // Actually swap
            p1->next = p2->next;
            p2->next = p1;

           //update the point 
            point->next = p2;
            point = p1;
        }

        // Return the start node
        return first->next;
    }
};


