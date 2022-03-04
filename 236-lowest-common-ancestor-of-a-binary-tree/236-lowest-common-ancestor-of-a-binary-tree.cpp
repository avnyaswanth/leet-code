/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define null NULL
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == null)
            return root;
        TreeNode *l = NULL, *r = NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        l = lowestCommonAncestor(root->left, p, q);
        r = lowestCommonAncestor(root->right, p, q);
        if(l && r)
            return root;
        if(l)
            return l;
        return r;
    }
};