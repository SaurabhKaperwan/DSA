//BFS
class Solution 
{
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
        {
            unordered_set<string> s(wordList.begin(), wordList.end());
            queue<pair<string,int>> q;
            q.push({beginWord, 1});
            s.erase(beginWord);

            while(!q.empty())
            {
                string word = q.front().first;
                int step = q.front().second;
                q.pop();
                if(word == endWord)
                    return step;

                for(int i = 0; i < word.size(); i++)
                {
                    string originalWord = word;
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;
                        if(s.find(word) != s.end())
                        {
                            q.push({word, step+1});
                            s.erase(word);
                        }
                    }
                    word = originalWord;
                }
            }
            return 0;
        }
};
