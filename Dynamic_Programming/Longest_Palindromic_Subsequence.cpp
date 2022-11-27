//MEMOIZATION

//Memoization

class Solution 
{
    public:

        int longestCommonSubsequence(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
        {
            if(i==0 or j==0)
                return 0;
            
            if(dp[i][j]!=-1)
                return dp[i][j];

            if(s1[i-1] == s2[j-1])
            {
                return 1+longestCommonSubsequence(s1,s2,i-1,j-1,dp);
            }

            int l1=longestCommonSubsequence(s1,s2,i-1,j,dp);
            int l2=longestCommonSubsequence(s1,s2,i,j-1,dp);

            return dp[i][j] = max(l1,l2);
        }

        int longestPalindromeSubseq(string s) 
        {
            int size  = s.size();
            vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
            string newString = s;
            reverse(s.begin(),s.end());
            return longestCommonSubsequence(s,newString,size,size,dp);
        }
};

//TABULATION

//Tabulation

class Solution 
{
    public:

         int longestCommonSubsequence(string text1, string text2) 
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
            return dp[n][m];
            
        }

        int longestPalindromeSubseq(string s) 
        {
            int size  = s.size();
            vector<vector<int>> dp(size+1,vector<int>(size+1,0));
            string newString = s;
            reverse(s.begin(),s.end());
            return longestCommonSubsequence(s,newString);
            
        }
};
