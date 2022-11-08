class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string,vector<string>> ump;
            for(auto word : strs)
            {
                string temp=word;
                sort(temp.begin(),temp.end());
                ump[temp].push_back(word);
            }   

            vector<vector<string>> ans;
            ans.resize(ump.size(), {});
            int i=0;
            for(auto ele : ump)
            {
                for(auto words : ele.second)
                {
                    ans[i].push_back(words);
                }
                i++;
            }
            return ans;
        }
};
