class Solution 
{
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
            vector<int> ans;
            stack<int> st;
            unordered_map<int, int> next_gre;

            for(int i = nums2.size() - 1; i >= 0; i--)
            {
                int num = nums2[i];
                while(!st.empty() && st.top() <= num)
                {
                    st.pop();
                }

                int res=(st.empty())? -1:st.top();

                next_gre.insert({num, res});
                st.push(num);

            }
            for (auto num : nums1) 
            {
                ans.push_back(next_gre[num]);
            }

            return ans;
        }
};
