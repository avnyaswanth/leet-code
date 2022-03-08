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
#define pb(x) push_back(x)
class Solution {
public:
    void inorder(Node *root, vector<int> &in)
    {
        if(!root)
            return ;
        inorder(root->left, in);
        in.pb(root->val);
        inorder(root->right, in);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);
        int i = 0, j = in.size()-1;
        while(i < j)
        {
            int sum = in[i] + in[j];
           if(sum == k)
               return true;
            else if(sum < k)
                i++;
            else j--;
        }
        return false;
    }
};