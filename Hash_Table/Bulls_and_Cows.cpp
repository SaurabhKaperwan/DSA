class Solution 
{
    public:
        string getHint(string secret, string guess) 
        {
            unordered_map<char,int> ump;
            int bulls=0,cows=0;
            
            for(int i=0;i<secret.size();i++)
            {
                if(secret[i]==guess[i])
                    bulls++;
                else
                    ump[secret[i]]++;
            }
            
            for(int i=0;i<secret.size();i++)
            {
                if(secret[i]!=guess[i])
                {
                    if(ump[guess[i]]>0)
                    {
                        cows++;
                        ump[guess[i]]--;
                    }
                    
                }
            }
            
            return to_string(bulls)+"A"+to_string(cows)+"B";
        }
};
