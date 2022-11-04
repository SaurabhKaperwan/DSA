class Solution 
{
    public:

        int check(vector<int>& nums)
        {
            int prev=nums[0];
            int prev2=0;
            for(int i=1;i<nums.size();i++)
            {
                int pick=nums[i];
                if(i>1)
                    pick+=prev2;
                int notPick=prev;
                prev2=prev;
                prev=max(pick,notPick);
            }

            return prev;
        }

        int rob(vector<int>& nums) 
        {
            vector<int> ans1;
            vector<int> ans2;

            if(nums.size()==1)
                return nums[0];
            
            for(int i=0;i<nums.size();i++)
            {
                if(i!=0)
                    ans1.push_back(nums[i]);
                if(i!=nums.size()-1)
                    ans2.push_back(nums[i]);
            }
            return max(check(ans1),check(ans2));
        }
};
