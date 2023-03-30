class Solution 
{
    public:
        vector<int> parent;
        vector<int> sizeArray;
        bool isValid(int row, int col, int n)
        {
            if(row >= 0 && row < n && col >=0 && col < n)
                return true;
            return false;
        }

        int findUParent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u, int v)
        {
            int up = findUParent(u);
            int vp = findUParent(v);
            if(up == vp) 
                return;
            else if(sizeArray[up] < sizeArray[vp])
            {
                parent[up] = vp;
                sizeArray[vp] += sizeArray[up];
            }
            else
            {
                parent[vp] = up;
                sizeArray[up] += sizeArray[vp];
            }
    }

        int largestIsland(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            int size = n * n;
            parent.resize(size);
            sizeArray.resize(size, 1);
            int delRow[] = {-1 , 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i = 0; i < size; i++)
                parent[i] = i;
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        int node = i * n + j;
                        for(int k = 0; k < 4; k++)
                        {
                            int newRow = i + delRow[k];
                            int newCol = j +delCol[k];
                            if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                            {
                                int adjNode = newRow * n + newCol;
                                int nodeP = findUParent(node);
                                int adjNodeP = findUParent(adjNode);
                                if( nodeP != adjNodeP)
                                    unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
            int ans = 0, count = 0;
            bool flag = false;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 0)
                    {
                        flag = true;
                        unordered_set<int> s;
                        int count = 1;
                        for(int k = 0; k < 4; k++)
                        {
                            int newRow = i + delRow[k];
                            int newCol = j +delCol[k];
                            if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                            {
                                int adjNode = newRow * n + newCol;
                                int adjNodeP = findUParent(adjNode);
                                s.insert(adjNodeP);
                            }
                        }
                        for(auto &it : s)
                        {
                            count += sizeArray[it];
                        }
                        ans = max(ans, count);
                    }
                }
            }
            if(flag == false)
                return n * n;
            return ans;
        }
};
