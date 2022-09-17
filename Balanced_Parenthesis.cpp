class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> st;
        for(char itr : s)
        {
            if(itr=='{' or itr=='[' or itr=='(')
            {
                st.push(itr);
            }
            else
            {
                if(  (st.top()=='(' && itr==')' )  || (st.top()=='{' && itr=='}' ) || (st.top()=='[' && itr==']' ) )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        
        return false;
    }
};
