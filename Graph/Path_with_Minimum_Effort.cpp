class Solution 
{
    public:
        int minimumEffortPath(vector<vector<int>>& heights) 
        {
            priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > pq;
            int n = heights.size();
            int m = heights[0].size();
            vector<vector<int>> dist(n,vector<int>(m,1e9));
            dist[0][0] = 0;
            pq.push({0,{0,0}});
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1}; 
            while(!pq.empty())
            {
                auto it = pq.top();
                int diff = it.first;
                int row = it.second.first;
                int col = it.second.second;
                pq.pop();
                if( row == n-1 and col == m-1)
                        return diff;

                for(int i = 0; i < 4; i++)
                {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if(newRow < n and newRow >= 0 and newCol < m and newCol >=0)
                    {
                        int newEffort = max(diff, abs(heights[newRow][newCol] - heights[row][col]));
                        if(newEffort < dist[newRow][newCol])
                        {
                            pq.push({newEffort,{newRow,newCol}});
                            dist[newRow][newCol] = newEffort;
                        }
                    }
                }
            }
            return -1;

        }
};
