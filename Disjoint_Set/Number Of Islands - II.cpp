//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    
    void unionOfIsland(int u, int v)
    {
        parent[v] = u;
    }
    
    bool isValid(int row, int col, int n, int m)
    {
        if(row >= 0 && row < n && col >=0 && col < m)
            return true;
        return false;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        int size = n * m;
        parent.resize(size);
        for(int i = 0; i < size; i++)
            parent[i] = i;
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands = 0;
        vector<int> ans;
        
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if(visited[row][col] == 1)
            {
                ans.push_back(islands);
                continue;
            }
            
            islands++;
            visited[row][col] = 1;
            
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(isValid(newRow, newCol, n ,m) && visited[newRow][newCol] == 1)
                {
                    int node = row * m + col;
                    int adjNode = newRow * m + newCol;
                    node = findUParent(node);
                    adjNode = findUParent(adjNode);
                    if( node != adjNode)
                    {
                        unionOfIsland(node, adjNode);
                        islands--;
                    }
                }
            }
            ans.push_back(islands);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
