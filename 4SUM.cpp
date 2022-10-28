// 3 Pointer + Binary Search + Set
class Solution 
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            set<vector<int>> ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                    for(int k=j+1;k<nums.size();k++)
                    {
                        long x=(long)target-(long)nums[i]-(long)nums[j]-(long)nums[k];
                        
                        if(binary_search(nums.begin()+k+1,nums.end(),x))
                        {
                           ans.insert(vector<int>{nums[i],nums[j],nums[k],(int)x}); 
                        }
                    }
                }
            }
            
            vector<vector<int>> res(ans.begin(),ans.end());
            return res;
        }
};
