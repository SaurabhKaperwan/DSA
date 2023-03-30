class Solution 
{
    public:
        bool isValid(vector<vector<char>>& board, int i, int j)
        {
            if(i >= 0 && i < board.size() && j >=0 && j < board[0].size())
                return true;
            return false;
        }

        bool dfs(int index, vector<vector<char>>& board, int i, int j, string& word)
        {
            if(index == word.size())
                return true;
            
            if(!isValid(board, i, j) || board[i][j] == '.')
            {
                return false;
            }
            if(board[i][j] != word[index])
                return false;
            char temp = board[i][j];
            board[i][j] = '.';

            if(dfs(index + 1, board, i - 1, j, word) || dfs(index + 1, board, i + 1, j, word) || dfs(index + 1, board, i , j - 1, word) || dfs(index + 1, board, i, j + 1, word))
            return true;
        
            board[i][j] = temp;
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) 
        {
            int n = board.size();
            int m = board[0].size();

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(dfs(0, board, i, j, word))
                        return  true;
                }
            }
            return false;

        }
};
