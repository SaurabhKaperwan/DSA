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
