class Solution 
{
    public:
        int countHousePlacements(int n) 
        {
            if(n==1)
                return 4;
            if(n==2)
                return 9;
            long prev1=2;
            long prev2=3;
            long curr;
            long mod=pow(10,9)+7;
            for(int i=3;i<=n;i++)
            {
                curr=(prev1+prev2)%mod;
                prev1=prev2;
                prev2=curr;
            }
            
            return (curr*curr)%mod;
        }
};
