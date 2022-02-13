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
        map<ListNode*, ListNode*> mp;
        ListNode *start = head;
        ListNode *end = NULL;
        ListNode *parent = NULL;
        while(start)
        {
            if(mp.find(start) != mp.end())
                return start;
            mp[start] = parent;
            parent = start;
            start = start->next;
        }
        return NULL;
    }
};