class Solution 
{
    public:
        string intToRoman(int num) 
        {
          int a[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
          string roman[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
            
            int i=0;
            string ans="";
            while(num!=0)
            {
                if(num>=a[i])
                {
                    ans+=roman[i];
                    num-=a[i];
                }
                else
                {
                    i++;
                }
            }
            return ans;
        }
};
