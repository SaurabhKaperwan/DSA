#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool isValid(string s) 
    {
        bool ans=false;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(s[i]==')' and st.top() != '(' or s[i]==']' and st.top() != '[' or  s[i]=='}' and st.top() != '{')
                {
                    return false;
                }
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        return ans;;
    }
};

int main()
{
    Solution obj;
    bool ans=obj.isValid("]");
    cout<<ans;

}
