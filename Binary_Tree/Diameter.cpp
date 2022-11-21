class Solution 
{
    public:

        int dfs(TreeNode *root,int& diameter)
        {
            if(root==NULL)
                return 0;
            int l=dfs(root->left,diameter);
            int r=dfs(root->right,diameter);
            diameter=max(diameter,l+r);
            return 1+max(l,r);
        }

        int diameterOfBinaryTree(TreeNode* root) 
        {
            int diameter=0;
            dfs(root,diameter);
            return diameter;
        }
};
