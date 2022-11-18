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







//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//Using BFS(Topo Sort)

class Solution 
{
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int> revAdj[V];
        vector<int> indegree(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);        
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : revAdj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
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
