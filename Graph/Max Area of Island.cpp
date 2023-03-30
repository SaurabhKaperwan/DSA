class Solution 
{
    public:

    int AreaOfIsland(int i, int j, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) 
            return 0;
        grid[i][j] = 0;
        return 1 + AreaOfIsland(i-1, j, grid) + AreaOfIsland(i, j-1, grid) + AreaOfIsland(i+1, j, grid) + AreaOfIsland(i, j+1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int max_area = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    max_area = max(max_area, AreaOfIsland(i, j, grid));
            }
        }
        return max_area;
    }
};
