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
