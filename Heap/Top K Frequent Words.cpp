class cmp
{
    public:
        bool operator() (pair<int,string> a , pair<int,string> b)
        {
            if( a.first == b.first )
                return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution 
{
    public:
        vector<string> topKFrequent(vector<string>& words, int k) 
        {
            vector<string> ans;
            unordered_map<string,int> mp;

            for(auto word : words)
            {
                mp[word]++;
            }


            priority_queue< pair<int,string> , vector< pair <int,string> > , cmp > pq;

            for(auto it : mp)
            {
                pq.push({it.second , it.first});
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }

            while(!pq.empty())
            {
                ans.insert(ans.begin() , pq.top().second);
                pq.pop();
            }
            return ans;

        }
};
