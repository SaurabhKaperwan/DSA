//Memoization

class Solution 
{
    public:
        
        int maxProfitUtil(vector<int>& prices, int ind, int canBuy, int cap, vector<vector<vector<int>>>& dp)
        {
            if(ind == prices.size() || cap == 0)
                return 0;
            if(dp[ind][canBuy][cap] != -1)
                return dp[ind][canBuy][cap];
            int profit = 0;
            if(canBuy)
            {
                int buy = -prices[ind] + maxProfitUtil(prices, ind+1, 0, cap, dp);
                int notBuy = 0 + maxProfitUtil(prices, ind+1, 1, cap, dp);
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[ind] + maxProfitUtil(prices, ind+1, 1, cap -1, dp);
                int notSell = maxProfitUtil(prices, ind+1, 0, cap, dp);
                profit = max(sell, notSell);
            }
            return dp[ind][canBuy][cap] = profit;
        }

        int maxProfit(vector<int>& prices) 
        {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2 , vector<int>(3, -1)));
            return maxProfitUtil(prices,0,1,2,dp);
        }
};

//Tabulation

class Solution 
{
    public:

        int maxProfit(vector<int>& prices) 
        {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2 , vector<int>(3, 0)));
            for(int ind = n-1; ind >= 0; ind--)
            {
                for(int buy = 0; buy < 2; buy++)
                {
                    for(int cap = 1; cap < 3; cap++)
                    {
                        int profit = 0;
                        if(buy)
                        {
                            int Buy = -prices[ind] + dp[ind+1][0][cap];
                            int notBuy = 0 + dp[ind+1][1][cap];
                            profit = max(Buy, notBuy);
                        }
                        else
                        {
                            int sell = prices[ind] + dp[ind+1][1][cap -1];
                            int notSell = dp[ind+1][0][cap];
                            profit = max(sell, notSell);
                        }
                        dp[ind][buy][cap] = profit;
                    }
                }
            }
            return dp[0][1][2];
        }
};
