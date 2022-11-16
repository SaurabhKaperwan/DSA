class Solution 
{
  public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for (int i = 0; i < 4; ++i)
        {
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow<n and newRow>=0 and newCol<m and newCol>=0 and grid[newRow][newCol]==1 and visited[newRow][newCol]==0)
            {
                dfs(grid,visited,newRow,newCol);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>> &grid) 
    {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 and !visited[0][i])
                dfs(grid,visited,0,i);
            if(grid[n-1][i]==1 and !visited[n-1][i])
                dfs(grid,visited,n-1,i);
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and !visited[i][0])
                dfs(grid,visited,i,0);
            if(grid[i][m-1]==1 and !visited[i][m-1])
                dfs(grid,visited,i,m-1);
        }

        for(int i=0;i<n;i++)
        {
            for (int j = 0; j < m; ++j)
            {
                if(grid[i][j]==1 and visited[i][j]==0)
                    count++;
            }
        }
        return count;
    }
};
