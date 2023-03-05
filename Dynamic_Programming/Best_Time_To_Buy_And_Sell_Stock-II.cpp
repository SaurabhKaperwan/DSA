//Memoization
class Solution 
{
    public:
        
        int maxProfitUtil(vector<int>& prices, int ind, int canBuy, vector<vector<int>>& dp)
        {
            if(ind == prices.size())
                return 0;
            if(dp[ind][canBuy] != -1)
                return dp[ind][canBuy];
            int profit = 0;
            if(canBuy)
            {
                int buy = -prices[ind] + maxProfitUtil(prices, ind+1, 0, dp);
                int notBuy = 0 + maxProfitUtil(prices, ind+1, 1, dp);
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[ind] + maxProfitUtil(prices, ind+1, 1, dp);
                int notSell = maxProfitUtil(prices, ind+1, 0, dp);
                profit = max(sell, notSell);
            }
            return dp[ind][canBuy] = profit;
        }

        int maxProfit(vector<int>& prices) 
        {
            vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
            return maxProfitUtil(prices,0,1,dp);
        }
};

//Tabulation

class Solution 
{
    public:
        
        int maxProfit(vector<int>& prices) 
        {
            int n = prices.size();
            vector<int> ahead(2,0), curr(2,0);
            for(int ind = n - 1; ind >=0; ind--)
            {
                for(int buy = 0; buy < 2; buy++)
                {
                    int profit = 0;
                    if(buy)
                    {
                        int Buy = -prices[ind] + ahead[0];
                        int notBuy = 0 + ahead[1];
                        profit = max(Buy, notBuy);
                    }
                    else
                    {
                        int sell = prices[ind] + ahead[1];
                        int notSell = ahead[0];
                        profit = max(sell, notSell);
                    }
                    curr[buy] = profit;
                }
                ahead = curr;
            }

            return ahead[1];
        }
};
