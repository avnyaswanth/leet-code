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
    void pathSum(vector<vector<int>> &paths, vector<int> path, TreeNode *root, int target, int &sum)
    {
        if(!root)
            return ;
        
        path.push_back(root->val);
        sum += root->val;
        
        
        if(sum == target && !root->left && !root->right)
        {
            paths.push_back(path);
            path.pop_back();
            sum -= root->val;
            return ;
        }
        
        
        pathSum(paths, path, root->left, target, sum);
        pathSum(paths, path, root->right, target, sum);
        path.pop_back();
        sum -= root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        int sum(0);
        pathSum(paths, path, root, targetSum, sum);
        return paths;
    }
};