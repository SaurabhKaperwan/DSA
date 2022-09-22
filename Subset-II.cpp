class Solution {
public:
    
    void giveSubset(vector<vector<int>> & ans,vector<int> & nums,int ind,vector<int> & check)
    {
            ans.push_back(check);   
        for(int i=ind;i<nums.size();i++)
        {
            if(i != ind and nums[i-1]==nums[i])
                continue;
             check.push_back(nums[i]);
             giveSubset(ans,nums,i+1,check);
             check.pop_back();   
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> check;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        giveSubset(ans,nums,0,check);
        return ans;
    }
};
