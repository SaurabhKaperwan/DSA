class Solution 
{
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
        {
            int m=maze.size();
            int n=maze[0].size();
            int row = entrance[0];
            int col = entrance[1];

            vector<vector<int>> visited(m,vector<int>(n,0));

            int mini=INT_MAX;

            queue<pair< pair<int,int> ,int >> q;
            q.push({{row,col},0});
            visited[row][col]=1;

            int delRow[]={-1,0,1,0};
            int delCom[]={0,1,0,-1};

            while(!q.empty())
            {
                int irow=q.front().first.first;
                int icol=q.front().first.second;
                int steps=q.front().second;
                q.pop();
                if((irow == m-1 or icol == n-1 or irow==0 or icol==0) and maze[irow][icol]=='.' and (irow != row or icol != col))
                {
                    mini=min(mini,steps);
                }
                for(int i=0;i<4;i++)
                {
                    int newRow=irow+delRow[i];
                    int newCol=icol+delCom[i];

                    if(newRow >=0 and newRow < m and newCol >=0 and newCol <n and !visited[newRow][newCol] and maze[newRow][newCol]=='.')
                    {
                        q.push({{newRow,newCol},steps+1});
                        visited[newRow][newCol]=1;
                    }
                }
            }

            if(mini == INT_MAX)
                return -1;
            return mini;
        }
};
