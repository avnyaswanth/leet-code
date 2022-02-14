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
#define node ListNode
#define data val
class Solution {
public:
    
    node *reverse(node *h)
	{
		if(h==NULL||h->next==NULL)
		return h;
		node *prev = NULL,*cur = h,*after = h;
		while(cur!=NULL)
		{
			after = cur->next;
			cur->next = prev;
			prev = cur;
			cur = after;
		}
		return prev;
	}
	
	bool compare(node *cur,node *midstart)
	{
		while(midstart!=NULL)
		{
			if(cur->data!=midstart->data)
			return false;
			cur = cur->next;
			midstart = midstart->next;
		}
		return true;
	}
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
		return true;	
		node *mid = head;
		node *slow = head,*fast = head,*prev=head;
		while(fast&&fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		node *midstart,*cur = head;;
		if(fast!=NULL)
		{
			slow->next = reverse(slow->next);
			midstart = slow->next;
		}
		else
		{
			prev->next = reverse(slow);
			midstart = prev->next;
		}
		bool ans = compare(head,midstart);
		return ans;
    }
};