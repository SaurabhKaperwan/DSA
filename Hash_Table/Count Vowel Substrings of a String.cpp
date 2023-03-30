class Solution 
{
    public:

        bool isVowel(int ch)
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
            return false;
        }
        int countVowelSubstrings(string word) 
        {
            int n = word.size();
            int ans  = 0;
            unordered_map<char,int> ump;
            for(int i = 0; i < n; i++)
            {
                ump.clear();
                for(int j = i; j < n && isVowel(word[j]); j++)
                {
                    ump[word[j]]++;
                    if(ump.size() == 5)
                    ans++;
                }

            }
            return ans;
        }
};
