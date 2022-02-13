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
    
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode *start = head;
        int count = length(head);
        k = k % count;
        if(k == 0 || k == count || count == 0)
            return head;
        ListNode *prev = start , *cur = start;
        for(int i=0;i<count-k;++i)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        ListNode *res = cur;
        while(cur)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = head;
        return res;
        
    }
};