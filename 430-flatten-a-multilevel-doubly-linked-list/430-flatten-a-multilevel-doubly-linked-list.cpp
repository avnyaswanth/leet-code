/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while(cur)
        {
            if(cur->child)
            {
                Node *next = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                Node *childcur = cur->next;
                while(childcur->next)
                    childcur = childcur->next;
                childcur->next = next;
                if(next)
                    next->prev = childcur;
            }
            cur = cur->next;
        }
        return head;
    }
};