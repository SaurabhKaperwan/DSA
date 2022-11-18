//Using DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    // Function to detect cycle in a directed graph.
    //Visited=>1
    //Path Visited=>2
    
    bool dfs(int node,vector<int> adj[],int visited[])
    {
        visited[node]=2;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited)==true)
                    return true;
            }
            else if(visited[it]==2)
                return true;
        }
        visited[node]--;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        int visited[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited)==true)
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    // Function to detect cycle in a directed graph.
    
    //Using Topo Sort,BFS,Khan's Algo
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        int indegree[V]={};
        
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count == V)
            return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
