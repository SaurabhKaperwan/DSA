//Memoization
#include <bits/stdc++.h> 

int min_total(int i,vector<int> & heights,vector<int> & dp)
{
    if(i==0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    
    int l=min_total(i-1,heights,dp)+abs(heights[i]-heights[i-1]);
    int r=INT_MAX;
    if(i>1)
        r=min_total(i-2,heights,dp)+abs(heights[i]-heights[i-2]);
    
    return dp[i]=min(l,r);

}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return min_total(n-1,heights,dp);    
}



//Tabulation
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int l = dp[i-1]+abs(heights[i]-heights[i-1]);
        int r=INT_MAX;
        if(i>1)
            r = dp[i-2]+abs(heights[i]-heights[i-2]);
        
        dp[i]=min(l,r);                        
    }
    return dp[n-1];
}




//Tabulation (Space Optimized )
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int l = prev+abs(heights[i]-heights[i-1]);
        int r=INT_MAX;
        if(i>1)
            r = prev2+abs(heights[i]-heights[i-2]);
        prev2=prev;
        prev=min(l,r);
    }
    return prev;
}
