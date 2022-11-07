class Solution 
{
    public:
        int maximum69Number (int num) 
        {
            int temp=num;
            int rem;
            int itr;
            int digit=0;
            while(temp!=0)
            {
                 digit++;
                rem=temp%10;
                if(rem==6)
                    itr=digit;
                temp=temp/10;
               
            }
            num=num+3*pow(10,itr-1);
            return num;
        }
};

//Using String Conversion
class Solution 
{
    public:
        int maximum69Number (int num) 
        {
            string s=to_string(num);
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='6')
                {
                    s[i]='9';
                    break;
                }
            }
            return stoi(s);
        }
};
