class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            set<int> hashSet;
            if(nums.size()==0||nums.size()==1)
                return nums.size();
            for(auto num : nums)
            {
                hashSet.insert(num);
            }
            int longestStreak=0;
            
            for(auto num : nums)
            {
                if(!hashSet.count(num-1))
                {
                    int currentNum=num;
                    int currentStreak=1;
                    
                    while(hashSet.count(currentNum+1))
                    {
                        currentNum+=1;
                        currentStreak+=1;
                    }
                    longestStreak=max(longestStreak,currentStreak);
                }
            }
            return longestStreak;
        }
};
