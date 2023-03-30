class Solution 
{
    public:
        int mostFrequentEven(vector<int>& nums) 
        {   
            int n = nums.size();
            map<int,int> mp;
            for(int num : nums)
            {
                if(num % 2 == 0)
                {
                    mp[num]++;
                }
            }
            int ele = -1 , freq = -1;
            for(auto it : mp)
            {
                if(freq < it.second)
                {
                    ele = it.first;
                    freq = it.second;
                }
            }
            return ele;
        }
};
