class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans,bool status)
    {
        if(root==NULL)
            return ;
        if(root->left == NULL || root->right == NULL)
            ans.push_back(-101);
        
        if(status == 1)
        {
            inorder(root->left,ans,status);
            ans.push_back(root->val);
            inorder(root->right,ans,status);
        }
        else
        {
            inorder(root->right,ans,status);
            ans.push_back(root->val);
            inorder(root->left,ans,status);
        }
    }
    
    bool SymmetricUtil(vector<int> &nodes,vector<int> &mirnodes)
    {
        int i=0,n=nodes.size();
        for(int i=0;i<n;++i)
            if(nodes[i] != mirnodes[i])
                return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> nodes,mirnodes;
        inorder(root,nodes,1);
        inorder(root,mirnodes,0);
        return SymmetricUtil(nodes,mirnodes);
    }
};