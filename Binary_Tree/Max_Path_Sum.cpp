class Solution 
{
    public:

        int giveMaxPath(TreeNode* root , int& maxPath)
        {
            if(root == NULL)
                return 0;
            
            int l = max(0,giveMaxPath(root->left , maxPath ));
            int r = max(0,giveMaxPath(root->right , maxPath ));

            maxPath = max(maxPath , root->val+l+r);

            return root->val+max(l,r);
        }

        int maxPathSum(TreeNode* root) 
        {
            int maxPath = INT_MIN;
            giveMaxPath( root , maxPath );
            return maxPath;
        }
};
