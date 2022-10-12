class Solution 
{
    public:
        int largestPerimeter(vector<int>& nums) 
        {
            sort(nums.begin(),nums.end());
            int lp=0;
            for(int i=nums.size()-1;i>=2;i--)
            {
                if(nums[i]<nums[i-1]+nums[i-2])
                {
                    if(lp<nums[i]+nums[i-1]+nums[i-2])
                        lp=nums[i]+nums[i-1]+nums[i-2];
                }
            }
            
            return lp;
        }
};
