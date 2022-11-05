//Tabulation

class Solution 
{
    public:

        int uniquePaths(int m,int n)
        {
            vector<vector<long>> dp(m+1,vector<long>(n+1,-1));
            dp[0][0]=1;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0 and j==0)
                        continue;
                    else
                    {
                        long down=0;
                        long right=0;
                        if(i>0)
                            down=dp[i-1][j];
                        if(j>0)
                            right=dp[i][j-1];

                        dp[i][j]=down+right;
                    }
                }
            }
            return dp[m-1][n-1];
        }
};
