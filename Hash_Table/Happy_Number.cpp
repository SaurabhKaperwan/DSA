class Solution 
{
    public:

        int digitSum(int n)
        {
            int sum=0;
            while(n!=0)
            {
                int rem=n%10;
                n=n/10;
                sum+=rem*rem;
            }
            return sum;
        }

        bool isHappy(int n) 
        {
            set<int> visit;
            while(n!=1)
            {
                if(visit.count(n)>0)
                    return false;
                visit.insert(n);
                n=digitSum(n);
            }
            return true;
        }
};
