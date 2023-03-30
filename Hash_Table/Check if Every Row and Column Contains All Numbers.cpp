class Solution 
{
    public:
        bool checkValid(vector<vector<int>>& matrix) 
        {
            unordered_map<int,int> ump;
            int n = matrix.size();
            for(auto row : matrix)
            {
                ump.clear();
                for(auto ele : row)
                {
                        ump[ele]++;
                }
                if(ump.size()!= n)
                    return false;
            }
            for(int i = 0; i < n; i++)
            {
                ump.clear();
                for(int j = 0; j < n; j++)
                {
                        ump[matrix[j][i]]++;
                }
                if(ump.size()!= n)
                    return false;
            }
            return true;
        }
};
