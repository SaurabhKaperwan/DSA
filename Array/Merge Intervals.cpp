class Solution 
{
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) 
        {
            int i = 0;
            vector<vector<int>> ans;
            sort(intervals.begin(), intervals.end());
            ans.push_back(intervals[0]);
            for(int j = 0; j < intervals.size(); j++)
            {
                if(ans[i][1] >= intervals[j][0])
                {
                    vector<int> temp;
                    temp.push_back(ans[i][0]);
                    if(intervals[j][1] > ans[i][1])
                        temp.push_back(intervals[j][1]);
                    else
                        temp.push_back(ans[i][1]);
                    ans.pop_back();
                    ans.push_back(temp);
                }
                else
                {
                    vector<int> temp;
                    i++;
                    temp.push_back(intervals[j][0]);
                    temp.push_back(intervals[j][1]);
                    ans.push_back(temp);
                }
            }
            return ans;
        }
};
