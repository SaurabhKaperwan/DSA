// Using Map

class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            unordered_map<int,int> mp;
            int ans;
            for(auto num : nums)
            {
                mp[num]++;
            }
            
            for(auto itr : mp)
            {
                if(itr.second > nums.size()/2)
                {
                    ans=itr.first;
                    break;
                }
            }
            return ans;
        }
};

//Using Boyer - Moore's Voting Algo

class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            int n = nums.size();
            int el;
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(cnt == 0)
                {
                    cnt = 1;
                    el = nums[i];
                }
                else if(el == nums[i])
                    cnt++;
                else
                    cnt--;
            }
            return el;
        }
};
