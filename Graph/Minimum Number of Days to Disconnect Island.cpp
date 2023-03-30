class Solution 
{
    public:

        bool isValid(int n, int m, int row, int col)
        {
            if(row < 0 || col < 0 || row >= n || col >= m)
                return false;
            return true;
        }

        int countIsland(vector<vector<int>>& grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> visited(n, vector<int>(m,0));

            int cnt = 0;
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(!visited[i][j] && grid[i][j] == 1)
                    {
                        cnt++;
                        dfs(grid, visited, i, j);
                    }
                }
            }
            return cnt;

        }
    
        void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col)
        {
            visited[row][col] = 1;
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(isValid(grid.size(), grid[0].size(), newRow, newCol) && grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0)
                {
                    dfs(grid, visited, newRow, newCol);
                }
            }
        }
        int minDays(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            int m = grid[0].size();
            
            if(countIsland(grid) == 0 || countIsland(grid) > 1)
                return 0;

            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] == 1)
                        cnt++;
                }
            }
            if(cnt == 1)
                return 1;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                        if(countIsland(grid) > 1)
                            return 1;
                        grid[i][j] = 1;

                    }
                }
            }
            return 2;
        }
};
