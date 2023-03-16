class Solution 
{
    public:
        vector<int> parent;
        int findUParent(int node)
        {
            if(parent[node] == node)
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionOfAccounts(int u, int v)
        {
            u = findUParent(u);
            v = findUParent(v);
            if(u != v)
                parent[v] = u;

        }
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
        {
            int n = accounts.size();
            parent.resize(n);
            for(int i = 0; i < n; i++)
                parent[i] = i;
            
            unordered_map<string, int> ump;

            for(int i = 0; i < n; i++)
            {
                for(int j = 1; j < accounts[i].size(); j++)
                {
                    string account = accounts[i][j];
                    if(ump.find(account) == ump.end())
                        ump.insert(make_pair(account, i));
                    else
                    {
                        int parent = ump[account];
                        unionOfAccounts(parent, i);

                    }
                }
            }

            vector<string> mergeString[n];
            for(auto it : ump)
            {
                string account = it.first;
                int node = it.second;
                node = findUParent(node);
                mergeString[node].push_back(account);
            }
            vector<vector<string>> ans;
            for(int i = 0; i < n; i++)
            {
                if(mergeString[i].size() == 0)
                    continue;
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(mergeString[i].begin(), mergeString[i].end());

                for(auto it : mergeString[i])
                    temp.push_back(it);
                ans.push_back(temp);
            }
            return ans;
        }
};
