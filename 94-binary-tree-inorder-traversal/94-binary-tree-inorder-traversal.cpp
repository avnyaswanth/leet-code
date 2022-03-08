/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define Node TreeNode
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<Node*> stk;
        stk.push(root);
        Node *cur = root->left;
        
        while(!stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);
            cur = cur->right;
            if(cur!= nullptr)
            {
                while(cur)
                {
                    stk.push(cur);
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};