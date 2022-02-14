class Solution {
public:
    ListNode* reverse(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *revHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
            
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        // if(head->next->next == NULL)
        //     return head->val == head->next->val;
        
        ListNode *slow = new ListNode();
        slow->next = head;
        ListNode *fast = slow;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *revhead = reverse(slow->next);
        ListNode *revstart = revhead;
        ListNode *headstart = head;
        // slow->next = NULL;

        while(revstart)
        {
            if(headstart->val != revstart->val)
                return false;
            headstart = headstart->next;
            revstart = revstart->next;
        }
        
        slow->next = reverse(revhead);
        return true;
    }
};