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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* start = new ListNode();
        start -> next = head;
        ListNode *ans = new ListNode(-1);
        ListNode *res = ans;
        
        int count = length(head);
        
        for(int j=0;j<count/k;++j)
        {   
            stack<ListNode*> stk;
            int i = 0;
            for(i=0;i<k && start !=NULL;++i)
            {
                start = start->next;
                stk.push(start);
            }
            
            while(!stk.empty())
            {
                ListNode *cur = stk.top();
                stk.pop();
                ListNode *temp = new ListNode(cur->val);
                ans->next = temp;
                ans = temp;
            }
        }
        
        ans->next = start->next;
        
        return res->next;
    }
};