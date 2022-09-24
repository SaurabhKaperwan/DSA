class Solution 
{
public:
    
    void dfs(vector<vector<int>> & image,int row,int col,int color,int ini_col,int delRow[],int delCol[])
    {
        int n=image.size();
        int m=image[0].size();
        image[row][col]=color;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 and nrow < n and ncol>=0 and ncol<m and image[nrow][ncol]==ini_col and image[nrow][ncol] != color)
            {
                dfs(image,nrow,ncol,color,ini_col,delRow,delCol);
            }
            
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int ini_col=image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(image,sr,sc,color,ini_col,delRow,delCol);
        return image;
    }
};
