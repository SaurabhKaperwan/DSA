//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int N, int k) 
    { 
        int sum = 0;
        int len = 0;
        for(int i = 0; i < N; i++)
        {
            sum = 0;
            for(int j = i; j < N; j++)
            {
                sum += a[j];
                if(sum == k)
                    len = max(len, (j - i + 1));
            }
        }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends


//Using Map

long long sum = 0;
    int maxLen = 0;
    unordered_map<long long , int> preSum;

    for(int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if(sum == k)
        {
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;

        if(preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
	//For this case [2,0,0,3]
        if(preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }
    }
    return maxLen;
