class Solution
{
    public:
    
    vector<int> topoSort(vector<int> adj[],int K)
    {
        vector<int> indegree(K,0);
        vector<int> topo;
        for(int i=0;i<K;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<K;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        return topo;
    }
    
    
    string findOrder(string dict[], int N, int K) 
    {
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            
            int minLength=min(s1.size(),s2.size());
            
            for(int j=0;j<minLength;j++)
            {
                if(s1[j]!=s2[j])
                {
                    int u=s1[j]-'a';
                    int v=s2[j]-'a';
                    adj[u].push_back(v);
                    break;
                }
            }
        }
        
        vector<int> topo=topoSort(adj,K);
        
        string ans="";
        
        for(auto it : topo)
        {
            ans=ans+char(it+'a');
        }
        
        return ans;
    }
};
