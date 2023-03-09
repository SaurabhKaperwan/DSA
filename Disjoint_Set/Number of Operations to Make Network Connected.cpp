class Solution 
{
    public:
        vector<int> parent;
        ;
        int findUParent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionSet(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            parent[v] = u;
        }

        int makeConnected(int n, vector<vector<int>>& connections) 
        {
            parent.resize(n);
            int notNeeded = 0;
            int components = 0;
            for(int i = 0; i < n; i++)
                parent[i] = i;
            
            for(auto it : connections)
            {
                int u = it[0];
                int v = it[1];
                if(findUParent(u) != findUParent(v))
                    unionSet(u , v);
                else
                    notNeeded++;
            }

            for(int i = 0; i < n; i++)
            {
                if(parent[i] == i)
                    components++;
            }
            cout<< components<<" "<<notNeeded;
            if(components - 1 <= notNeeded)
                return components-1;
            return -1;
        }
};
