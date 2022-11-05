class Solution 
{
    public:

        int givePaths(vector<vector<int>> & obstacleGrid,int row,int col,vector<vector<int>>& dp)
        {
            if(dp[row][col]!=-1)
                return dp[row][col];
            if(row==0 and col==0 and obstacleGrid[row][col]!=1)
                return 1;
            if(row<0 or col<0 or obstacleGrid[row][col]==1)
                return 0;
            int left=0,up=0;
            if(row!=0)
                up=givePaths(obstacleGrid,row-1,col,dp);
            if(col!=0)
                left=givePaths(obstacleGrid,row,col-1,dp);

            return dp[row][col]=up+left; 
        }

        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
        {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return givePaths(obstacleGrid,m-1,n-1,dp);
        }
};
