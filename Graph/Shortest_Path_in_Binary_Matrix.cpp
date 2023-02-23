class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        q.push({0,{0,0}});
        dist[0][0] = 0;
        int delRow[] = {-1,0,1,0,-1,-1,1,1};
        int delCol[] = {0,1,0,-1,-1,1,1,-1};
        while(!q.empty())
        {
            auto it = q.front();
            int weight = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] == 0 and dist[newRow][newCol] > weight + 1)
                {
                    dist[newRow][newCol] = weight + 1;
                    q.push({weight+1,{newRow,newCol}});
                }
            }

        }
        if(dist[n-1][m-1] == INT_MAX)
            return -1;
        return dist[n-1][m-1]+1;

    }
};
