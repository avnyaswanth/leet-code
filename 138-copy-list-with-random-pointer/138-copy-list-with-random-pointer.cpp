/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *h = head;
        while(h)
        {
            Node *next = h->next;
            Node *copynode = new Node(h->val);
            h->next = copynode;
            copynode->next = next;
            h = next;
        }
        h = head;
        while(h)
        {
            if(h->random)
                h->next->random = h->random->next;
            h = h->next->next;
        }
        h = head;
        Node *c = head->next;
        Node *copyhead = c;
        while(h)
        {
            Node *next = c->next;
            h->next = next;
            h = next;
            if(h)
                c->next = h->next;
            c = c->next;
        }
        return copyhead;
    }
};