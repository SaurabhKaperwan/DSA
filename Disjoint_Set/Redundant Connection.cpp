class Solution 
{
    public:
        vector<int> parent;
        int findUParent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionOfNodes(int u, int v)
        {
            parent[v] = u;
        }
        vector<int> findRedundantConnection(vector<vector<int>>& edges) 
        {
            int ans_u, ans_v;
            int n = edges.size();
            parent.resize(n + 1);
            for(int i = 1; i <= n; i++)
                parent[i] = i;
            
            for(auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int u_parent = findUParent(u);
                int v_parent = findUParent(v);
                if(u_parent != v_parent)
                    unionOfNodes(u_parent, v_parent);
                else
                {
                    ans_u = u;
                    ans_v = v;                  
                }
            }
            vector<int> ans;
            ans.push_back(ans_u);
            ans.push_back(ans_v);
            return ans;
        }
};
