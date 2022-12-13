class Solution 
{
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
        {
            vector<vector<int>> ans;

            priority_queue< pair<int , pair<int,int>>> pq;

            for(int i = 0 ; i < nums1.size() ; i++)
            {
                for(int j = 0 ; j < nums2.size()  ; j++)
                {
                    int sum = nums1[i] + nums2[j];
                    if(pq.size() < k)
                        pq.push({sum , {nums1[i] , nums2[j]}});
                    else if(pq.top().first > sum)
                    {
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else
                    {
                        break;
                    }
                }
            }

            while(!pq.empty())
            {
                vector<int> temp;
                temp.push_back(pq.top().second.first);
                temp.push_back(pq.top().second.second);
                pq.pop();
                ans.push_back(temp);
            }
            return ans;
        }
};
