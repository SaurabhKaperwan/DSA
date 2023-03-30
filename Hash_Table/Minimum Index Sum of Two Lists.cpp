class Solution 
{
    public:
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
        {
            unordered_map<string, int> ump;
            unordered_map<string, int> ump2;
            vector<string> ans;
            int i = 0;
            for(auto word : list1)
            {
                ump[word] += i;
                i++;
            }
            i = 0;
            int minSum = INT_MAX;


            for(auto word : list2)
            {
                if(ump.find(word) != ump.end())
                {
                    ump2[word] = ump[word] + i;
                    if(minSum > ump2[word])
                        minSum = ump2[word];
                }
                i++;
            }
            
            for(auto it : ump2)
            {
                if(it.second == minSum)
                    ans.push_back(it.first);
            }
            return ans;
        }
};
