//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Using BFS

class Solution
{
  public:
    
    bool detectCycle(int node,vector<int> adj[],int visit[])
    {
        queue<pair<int,int>> q;
        q.push({node,-1});
        visit[node]=1;
        
        while(!q.empty())
        {
            int temp=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto itr : adj[temp])
            {
                if(!visit[itr])
                {
                    q.push({itr,temp});
                    visit[itr]=1;
                }
                else if(parent != itr)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        int visit[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
                if(detectCycle(i,adj,visit) == true)
                    return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends



//Using DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[],int node,int parent,int visited[])
    {
        visited[node]=1;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(adj,it,node,visited))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        int visited[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(adj,i,-1,visited))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
