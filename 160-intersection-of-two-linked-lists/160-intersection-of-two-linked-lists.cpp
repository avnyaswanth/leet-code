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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = new ListNode(), *b = new ListNode();
        a->next = headA;
        b->next = headB;
        int x = 0, y = 0;
            // lengths - x for A, y for B
        while(a || b)
        {
            if(a)
            {
                x++;
                a = a->next;
            }
            if(b)
            {
                y++;
                b = b->next;
            }
        }
        a = headA;
        b = headB;
        int diff = abs(x - y);
        if(x < y)
            swap(a, b);
        for(int i=0;i<diff;++i)
            a = a->next;
        while(a != b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};