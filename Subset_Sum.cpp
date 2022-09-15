//Subset Sum - I
#include<bits/stdc++.h>
using namespace std;

void subsetSum(int ind,vector<int> & arr,vector<int> & ans,int sum)
{
    if(ind ==arr.size())
    {
        ans.push_back(sum);
        return;
    }   

    subsetSum(ind+1,arr,ans,sum+arr[ind]);
    subsetSum(ind+1,arr,ans,sum);
}

int main()
{
    vector<int> arr{2,3,5,6};
    vector<int> ans;
    int sum=0;
    subsetSum(0,arr,ans,sum);
    sort(ans.begin(),ans.end());
    cout<<"Subset Sum is:\n";
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
