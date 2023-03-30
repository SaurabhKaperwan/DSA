class Solution 
{
    public:

        void dfs(int v, vector<int> adj[], vector<bool>& visited, map<pair<int, int>, bool>& ump, int& count)
        {
            visited[v] = true;

            for(auto u : adj[v])
            {
                if(visited[u] == false)
                {
                    if(ump[{v, u}] == true)
                        count++;
                    dfs(u, adj, visited, ump, count);
                }
            }
        }
        int minReorder(int n, vector<vector<int>>& connections) 
        {
            map<pair<int, int> , bool> ump;
            vector<int> adj[n];
            vector<bool> visited(n, false);
            int count = 0;

            for(auto it : connections)
            {
                int u = it[0];
                int v = it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                ump[{u, v}] = true;
            }
            dfs(0, adj, visited, ump, count);
            return count;

        }
};
