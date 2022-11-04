//Memoization
class Solution 
{
    public:

        int giveRob(int ind,vector<int>& nums,vector<int>& dp)
        {
            if(ind==0)
                return nums[ind];
            if(ind<0)
                return 0;

            if(dp[ind] != -1)
                return dp[ind];
            
            int pick=nums[ind]+giveRob(ind-2,nums,dp);
            int notPick=giveRob(ind-1,nums,dp);

            return dp[ind]=max(pick,notPick);
        }

        int rob(vector<int>& nums) 
        {
            int n=nums.size();
            vector<int> dp(n+1,-1);
            return giveRob(n-1,nums,dp);
        }
};


//Tabulation(Space Optimized)
class Solution 
{
    public:
        int rob(vector<int>& nums) 
        {
            int prev=nums[0];
            int prev2=0;

            for(int i=1;i<nums.size();i++)
            {
                int take=nums[i];
                if(i>1)
                    take+=prev2;
                
                int notTake=prev;
                prev2=prev;
                prev=max(take,notTake);
            }
            return prev;
        }
};
