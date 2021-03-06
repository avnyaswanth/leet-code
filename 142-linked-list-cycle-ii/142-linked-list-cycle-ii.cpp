/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        while(second && second->next)
        {
            first = first->next;
            second = second->next->next;
            if(first == second)
                break;
        }
        if(!second || !second->next)
            return NULL;
        first = head;
        while(first != second)
        {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};