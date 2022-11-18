//Using DFS

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    bool dfs(int node,int visited[],int pathVisited[],int safeNode[],vector<int> adj[])
    {
        visited[node]=1;
        pathVisited[node]=1;
        vector<int> ans;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,pathVisited,safeNode,adj)==true)
                    return true;
            }
            
            else if(pathVisited[it]==1)
            {
                return true;
            }
                
        }
        safeNode[node]=1;
        pathVisited[node]=0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        int visited[V]={0};
        int safeNode[V]={0};
        int pathVisited[V]={0};
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,visited,pathVisited,safeNode,adj);
        }
        
        for(int i=0;i<V;i++)
        {
            if(safeNode[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
