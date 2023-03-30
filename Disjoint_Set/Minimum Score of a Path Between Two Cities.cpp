class Solution 
{
    public:

        int findUParent(vector<int>& parent, int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent, parent[node]);
        }

        int minScore(int n, vector<vector<int>>& roads) 
        {
           vector<int> parent(n + 1);
           vector<int> ans(n + 1);
           for(int i = 1; i <= n; i++)
                parent[i] = i;
            for(int i = 1; i <= n; i++)
                ans[i] = INT_MAX;
            for(auto &it : roads)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];

                int uP = findUParent(parent, u);
                int vP = findUParent(parent, v);

                ans[uP] = min(ans[uP], min(ans[vP], w));
                ans[vP] = min(ans[uP], min(ans[vP], w));

                if(uP != vP)
                {
                    if(uP > vP)
                        parent[uP] = vP;
                    else
                        parent[vP] = uP;
                }
            }
            return ans[1]; 
        }
};
