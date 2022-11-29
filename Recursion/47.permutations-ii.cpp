class Solution 
{
    public:

        void giveUniquePer(vector<int> nums ,int i,vector<vector<int>> &ans)
        {
            int n = nums.size();
            if(i==n-1)
            {
                ans.push_back(nums);
                return;
            }

            for(int j=i;j<n;j++)
            {
                if(i!=j and nums[i]==nums[j])
                    continue;
                
                swap(nums[i],nums[j]);
                giveUniquePer(nums,i+1,ans);
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) 
        {
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            giveUniquePer(nums,0,ans);
            return ans;
        }
};
