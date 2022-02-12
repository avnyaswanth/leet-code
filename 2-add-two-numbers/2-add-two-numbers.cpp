/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* start = new ListNode();
        ListNode* head = start;
        int carry = 0;
        while(l1 or l2)
        {
            int sum = 0;
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        if(carry)
            head->next = new ListNode(carry);
        return start->next;
    }
};