// Memoization

class Solution 
{
    public:

        int hlp(int ind , int amount , vector<int>& coins,vector<vector<int>> &dp)
        {

            if(dp[ind][amount] != -1)
                return dp[ind][amount];

            if(ind == 0)
            {
                if(amount % coins[ind] == 0 )
                {
                    return amount / coins[ind];
                }
                else 
                {
                    return 1e9;
                }
            }

            int notPick = 0 + hlp(ind-1,amount,coins,dp);

            int pick = 1e9;

            if(coins[ind] <= amount)
                pick = 1 + hlp(ind,amount - coins[ind] , coins,dp);

            return dp[ind][amount] = min(notPick,pick);
        }

        int coinChange(vector<int>& coins, int amount) 
        {
            int n = coins.size();
            vector<vector<int>> dp(n, vector<int> (amount+1,-1));
            int ans  = hlp(coins.size()-1,amount,coins,dp);
            if(ans<1e9)
                return ans;
            return -1;
        }
};



// Tabulation


class Solution 
{
    public:

        int coinChange(vector<int>& coins, int amount) 
        {
            int n = coins.size();
            vector<vector<int>> dp(n, vector<int> (amount+1,-1));
            
            for(int i = 0 ; i <= amount; i++)
            {
                if(i % coins[0] == 0)
                {
                    dp[0][i] = i / coins[0];
                }
                else
                {
                    dp[0][i] = 1e9;
                }
            }

            for(int i = 1 ; i < n ; i++)
            {
                for(int j = 0 ; j <= amount ;j++)
                {
                    int notPick = 0+dp[i-1][j];
                    int pick = INT_MAX;

                    if(coins[i] <= j)
                        pick = 1 + dp[i][j-coins[i]];
                    
                    dp[i][j] = min(pick,notPick);
                }
            }
            if(dp[n-1][amount] < 1e9)
                return dp[n-1][amount];
            
            return -1;
        }
};
