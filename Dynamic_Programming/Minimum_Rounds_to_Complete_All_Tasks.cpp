class Solution 
{
    public:
        int minimumRounds(vector<int>& tasks) 
        {
           unordered_map <int,int> ump;
            for(int i=0;i<tasks.size();i++)
            {
                ump[tasks[i]]++;
            }
            
            int count=0;
            for(auto itr : ump)
            {
                while(itr.second!=0)
                {
                    if(itr.second<=1)
                        return -1;
                    else
                    {
                        if(itr.second-3>=2 || itr.second-3==0)
                            itr.second-=3;
                        else
                            itr.second-=2;
                        count++;
                    }
                }
            }
            
            return count;
        }
};
