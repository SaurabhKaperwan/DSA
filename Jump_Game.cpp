class Solution 
{
    public:
        
        bool canJump(vector<int>& nums) 
        {
            bool ans=false;
            int minJump=0;
            for(int i=nums.size()-2;i>=0;i--)
            {
                if(nums[i] > minJump)
                    minJump=0;
                else
                {
                     minJump++;
                }
            }
            if(minJump==0)
                ans=true;
            return ans;
        }
};
