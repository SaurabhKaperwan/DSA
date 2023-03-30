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
class Solution 
{
    public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            if(root == NULL)
                return {};
            queue<TreeNode*> q;
            vector<vector<int>> bfs;
            q.push(root);
            while(!q.empty())
            {
                vector<int> currentLevel;
                int levelSize = q.size();
                
                for(int i = 0; i < levelSize; i++)
                {
                    TreeNode* currNode = q.front();
                    q.pop();
                    currentLevel.push_back(currNode -> val);
                    if(currNode -> left)
                        q.push(currNode -> left);
                    if(currNode -> right)
                        q.push(currNode -> right);
                }
                bfs.push_back(currentLevel);
            }
            return bfs;
        }
};
