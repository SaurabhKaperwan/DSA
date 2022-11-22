//Memoization

bool giveSubset(vector<int> &arr,int k,int n ,vector<vector<int>> &dp)
{
    if(k == 0)
        return true;
    
    if(n==-1)
        return false;
    
    if(dp[n][k]!=-1)
        return dp[n][k];
    
    bool notPick = giveSubset(arr,k,n-1,dp);
    
    bool pick = false;
    
    if(arr[n] <= k)
        pick = giveSubset(arr,k-arr[n],n-1,dp);
    
    return dp[n][k] =  pick or notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return giveSubset(arr,k,n-1,dp);
}


//Tabulation


bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notPick = dp[ind-1][target];
            bool pick = false;
            if(arr[ind] <= target)
                pick = dp[ind-1][target-arr[ind]];
            
            dp[ind][target]=pick or notPick;
        }
    }
    return dp[n-1][k];
}
