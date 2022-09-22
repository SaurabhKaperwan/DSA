class Solution 
{
    public:
        string reverseWords(string s) 
        {
            int start=0,tail;
            for(int i=0;i<=s.size();i++)
            {
                if(s[i]==' ' or s[i]=='\0')
                {
                    tail=i;
                    reverse(s.begin()+start,s.begin()+tail);
                    start=tail+1;
                }
            }
            
            return s;
        }
};
