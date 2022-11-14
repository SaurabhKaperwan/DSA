class Solution 
{
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        int rowSize=grid.size();
	    int colSize=grid[0].size();
	    
	    vector<vector<int>> dist(rowSize,vector<int>(colSize,0));
	    vector<vector<int>> visit(rowSize,vector<int>(colSize,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<rowSize;i++)
	    {
	        for(int j=0;j<colSize;j++)
	        {
	            if(grid[i][j]==0)
	           {
	               q.push({{i,j},0});
	               visit[i][j]=1;
	           }
	        }
	    }
	    
	    int delRow[]={-1,0,1,0};
	    int delCol[]={0,1,0,-1};
	    
	    while(!q.empty())
	    {
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int step=q.front().second;
	        q.pop();
	        dist[row][col]=step;
	        
	        for(int i=0;i<4;i++)
	        {
	            int newRow=row+delRow[i];
	            int newCol=col+delCol[i];
	            
	            if( newRow < rowSize and newRow >=0 and newCol < colSize and newCol >=0 and visit[newRow][newCol]==0 )
	            {
	                q.push({{newRow,newCol},step+1});
	                visit[newRow][newCol]=1;
	            }
	        }
	    }
	    return dist;                        
    }
};
