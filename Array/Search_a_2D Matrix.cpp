//Brute Force

class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size();
            int n = matrix[0].size();
            int row = 0, col = n -1;

            while(row < m and row >=0 and col < n and col >= 0)
            {
                if(matrix[row][col] == target)
                    return true;
                else if(matrix[row][col] < target)
                    row++;
                else
                    col--;
            }
            return false;
        }
};

//Using Binary Search

class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size();
            int n = matrix[0].size();
            int row = 0, col = n -1;

            while(row < m and row >=0 and col < n and col >= 0)
            {
                if(matrix[row][col] == target)
                    return true;
                else if(matrix[row][col] < target)
                    row++;
                else
                    col--;
            }
            return false;
        }
};
