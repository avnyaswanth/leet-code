/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, Node *root, vector<Node*> &visited) {
        for(auto cur : node->neighbors) 
        {
            if(visited[cur->val] == NULL)
            {
                Node *temp = new Node(cur->val);
                visited[cur->val] = temp;
                (root->neighbors).push_back(temp);
                dfs(cur, temp, visited);
            }
            else (root->neighbors).push_back(visited[cur->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node*> visited(101, NULL);
        Node *root = new Node(node->val);
        visited[node->val] = root;
        dfs(node, root, visited);
        return root;
        
    }
};