class Solution 
{
    public:

        void dfs(vector<vector<char>>& mat,vector<vector<int>>& visited,int row,int col,int n,int m)
        {
            visited[row][col]=1;
            
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                if( newRow>=0 and newRow<n and newCol>=0 and newCol<m and  !visited[newRow][newCol] and mat[newRow][newCol]=='O'  )
                {
                    dfs(mat,visited,newRow,newCol,n,m);
                }
            }
        }
        

        void solve(vector<vector<char>>& mat) 
        {
            int n=mat.size();
            int m=mat[0].size();
            vector<vector<int>>visited(n,vector<int> (m,0));
        
            for(int i=0;i<m;i++)
            {
                if(mat[0][i]=='O' and visited[0][i] ==0 )
                {
                    dfs(mat,visited,0,i,n,m);
                }
                if(mat[n-1][i]=='O' and visited[n-1][i] ==0 )
                {
                    dfs(mat,visited,n-1,i,n,m);   
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(mat[i][0]=='O' and visited[i][0] ==0 )
                {
                    dfs(mat,visited,i,0,n,m);
                }
                if(mat[i][m-1]=='O' and visited[i][m-1] ==0 )
                {
                    dfs(mat,visited,i,m-1,n,m);   
                }
            }
            
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]=='O' and visited[i][j]==0)
                        mat[i][j]='X';
                }
            }
            
        }
};
