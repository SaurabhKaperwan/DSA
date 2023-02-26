//Using Brute Force
class Solution 
{
    public:
        int missingNumber(vector<int>& nums) 
        {
            unordered_map<int,int> ump;

            for(int i = 0; i < nums.size(); i++)
            {
                ump[nums[i]]++;
            }

            for(int i = 1; i <= nums.size(); i++)
            {
                if(ump[i] == 0)
                    return i;
            }
            return 0;
        }
};

// Sum of n numbers : S(n) = (n * (n + 1))/2
class Solution 
{
    public:
        int missingNumber(vector<int>& nums) 
        {
            int n = nums.size();
            int sum = (n * (n + 1))/2;

            for(auto it : nums)
                sum -= it;
            return sum;
        }
};
