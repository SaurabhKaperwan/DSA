//Printing LCS
//Using Tabulation
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

       	void longestCommonSubsequence(string text1, string text2) 
        {
            int n=text1.size();
            int m=text2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i=0;i<n;i++)
                dp[i][0]=0;
            for(int j=0;j<m;j++)
                dp[0][j]=0;

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(text1[i-1]==text2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
            int len = dp[n][m];
            string ans="";
            for(int i=0;i<len;i++)
            	ans+='$';

            int index=len-1;

            int i=n,j=m;

            while(i>0 and j>0)
            {
            	if(text1[i-1]==text2[j-1])
            	{
            		ans[index]=text1[i-1];
            		index--;
            		i--;
            		j--;
            	}
            	else if(dp[i-1][j]>dp[i][j-1])
            	{
            		i--;
            	}
            	else
            	{
            		j--;
            	}
            }
            cout<<"LCS is:"<<ans;
        }
};

int main()
{
	Solution obj;
	obj.longestCommonSubsequence("abcde","ace");
}


//Using Memoization

class Solution 
{
    public:

        int lcsUtil(string  &text1,string &text2,int n,int m,vector<vector<int>> &dp,string &ans)
        {
            if(n<0 or m<0)
                return 0;

            if(dp[n][m]!=-1)
                return dp[n][m];
            if(text1[n]==text2[m])
            {
                ans+=text1[n];
                return dp[n][m]=1+lcsUtil(text1,text2,n-1,m-1,dp,ans);
            }
            
            return dp[n][m]= max(lcsUtil(text1,text2,n-1,m,dp,ans),lcsUtil(text1,text2,n,m-1,dp,ans));
        }

        int longestCommonSubsequence(string text1, string text2) 
        {
            int n=text1.size();
            int m=text2.size();
            string ans="";
            vector<vector<int>> dp(n,vector<int>(m,-1));
            int len=lcsUtil(text1,text2,n-1,m-1,dp,ans);
            reverse(ans.begin(),ans.end());
            cout<<ans;
            return len;

        }
};
