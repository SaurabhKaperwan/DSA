class Solution 
{
    public:
        void dfs(int node, vector<int> adj[], stack<int>& st, vector<int>& visited)
        {
            visited[node] = true;

            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    dfs(it, adj, st, visited);
                }
            }
            st.push(node);
        }
        void newDfs(int node, vector<int> revAdj[], vector<int>& visited, int& count)
        {
            visited[node] = true;
            count++;
            for(auto it : revAdj[node])
            {
                if(!visited[it])
                {
                    newDfs(it, revAdj, visited, count);
                }
            }
        }
        int longestCycle(vector<int>& edges) 
        {
            stack<int> st;
            int n = edges.size();
            vector<int> visited(n, 0);
            vector<int> adj[n];
            vector<int> revAdj[n];
            for(int i = 0; i < n; i++)
            {
                if(edges[i] != -1)
                {
                    adj[i].push_back(edges[i]);
                    revAdj[edges[i]].push_back(i);
                }
            }

            for(int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    dfs(i, adj, st, visited);
                }
            }

            fill(visited.begin(), visited.end(), 0);
            int maxCycle = 0;
            int count = 0;
            while(!st.empty())
            {
                int node  = st.top();
                st.pop();
                
                if(visited[node])
                    continue;
                count = 0;
                newDfs(node, revAdj, visited, count);
                maxCycle = (maxCycle < count) ? count : maxCycle;

            }
            if(maxCycle > 1)
                return maxCycle;
            return -1;

        }
};
