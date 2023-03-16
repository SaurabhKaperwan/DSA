//Using Map
class Solution 
{
    public:
        vector<int> majorityElement(vector<int>& nums) 
        {
            int n = nums.size();
            unordered_map<int,int> ump;
            vector<int> ans;
            for(auto it : nums)
                ump[it]++;

            for(auto it : ump)
            {
                if(it.second > n/3)
                    ans.push_back(it.first);
            }
            return ans;
        }
};

//Moore's Voting Algo

class Solution 
{
    public:
        vector<int> majorityElement(vector<int>& nums) 
        {
            //take any number it does not matter
            int ele1 = 0, ele2 = 1;
            int n = nums.size();
            int count1 = 0, count2 = 0;
            vector<int> ans;
            for(int num : nums)
            {
                if(num == ele1)
                    count1++;
                else if(num == ele2)
                    count2++;
                else if(count1 == 0)
                {
                    count1++;
                    ele1 = num;
                }
                else if(count2 == 0)
                {
                    count2++;
                    ele2 = num;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
            count1 = 0,count2 = 0;
            for(int num : nums)
            {
                if(num == ele1)
                    count1++;
                else if(num == ele2)
                    count2++;
            }
            if(count1 > n/3)
                ans.push_back(ele1);
            if(count2 > n/3)
                ans.push_back(ele2);
            return ans;
        }
};
