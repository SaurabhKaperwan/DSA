class Solution 
{
public:
    
    void giveParenthesis(vector<string> &ans,int op,int cl,string check,int n)
    {
        if(op==n and cl==n)
            ans.push_back(check);
        if(op > n or cl > n)
            return;
        if(cl > op)
            return;
        
        check.push_back('(');
        giveParenthesis(ans,op+1,cl,check,n);
        check.pop_back();
        check.push_back(')');
        giveParenthesis(ans,op,cl+1,check,n);
        check.pop_back();
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string check;
        giveParenthesis(ans,0,0,check,n);
        return ans;
    }
};
