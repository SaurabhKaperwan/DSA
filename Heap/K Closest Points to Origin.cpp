class Solution 
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
        {
            priority_queue< pair< float , pair<int,int> > > pq;
            vector<vector<int>> ans;

           for(auto it : points)
           {
               int x = it[0];
               int y = it[1];
               float dist = sqrt(x*x + y*y);

               if(pq.size() < k)
               {
                   pq.push({dist , {x,y}});
               }
               else if(pq.top().first > dist)
               {
                   pq.pop();
                   pq.push({dist , {x,y}});
               }
           }

           while(!pq.empty())
           {
               vector<int> temp;
               int x = pq.top().second.first;
               int y = pq.top().second.second;
               pq.pop();
               temp.push_back(x);
               temp.push_back(y);
               ans.push_back(temp);

           }
           return ans;
        }
};
