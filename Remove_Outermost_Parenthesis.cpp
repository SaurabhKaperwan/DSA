class Solution 
{
public:
    string removeOuterParentheses(string s) 
    {
        string ans;
        int ctr=0;
        for(auto itr : s)
        {
            if(itr=='(')
            {
                if(ctr++)
                {
                       ans.push_back(itr);
                }
            }
            else
            {
                ctr--;
                if(ctr)
                {
                    ans.push_back(itr);
                }
            }
        }
        return ans;
    }
};
