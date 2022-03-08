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
class Solution {
public:
    TreeNode* kthSmallest(TreeNode *root, int &i, int k)
    {
       if(!root)
           return nullptr;
        TreeNode *res = kthSmallest(root->left, i, k);
        if(res)
            return res;
        if(i == k)
            return root;
        i++;
        return kthSmallest(root->right, i, k);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int i = 1;
        return kthSmallest(root, i, k)->val;
    }
};