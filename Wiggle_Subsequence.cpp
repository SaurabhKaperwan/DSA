class Solution 
{
    public:
        int wiggleMaxLength(vector<int>& nums) 
        {
            int flag=0;
            int count=0;
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]<nums[i+1] and (flag==0 or flag==1))
                {
                    count++;
                    flag=-1;
                }
                else if(nums[i]>nums[i+1] and (flag==0 or flag==-1))
                {
                    count ++;
                    flag=1;
                }
            }
            return ++count;
        }
};
