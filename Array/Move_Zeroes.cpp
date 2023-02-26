class Solution 
{
    public:
        void moveZeroes(vector<int>& nums) 
        {
            int size = nums.size();
            int temp[size];
            int i;
            for(i = 0; i < size; i++)
            {
                if(nums[i] == 0)
                    break;
            }
            int j = i + 1;

            while(i < size && j < size)
            {
                if(nums[j] != 0)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                }
                j++;
            }
        }
};
