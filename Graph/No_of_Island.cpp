class Solution 
{
    public:

        void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int row,int col)
        {
            int n=grid.size();
            int m=grid[0].size();
            visited[row][col]=1;
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for (int i = 0; i < 4; i++)
            {
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && grid[newRow][newCol]=='1' && visited[newRow][newCol]==0)
                {
                    dfs(grid,visited,newRow,newCol);
                }
            }
        }

        int numIslands(vector<vector<char>>& grid) 
        {
            int count=0;
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>> visited(n,vector<int>(m,0));

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]=='1' and visited[i][j]==0)
                    {
                        dfs(grid,visited,i,j);
                        count++;
                    }
                }
             }
             return count;
        }
};
