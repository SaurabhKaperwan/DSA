//Combination Sum

#include<bits/stdc++.h>
using namespace std;

void combinationalSum(int ind,int target,int n,vector<int> &ds,vector<vector<int>> &ans,int a[])
{
    if(ind==n)
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if(target >= a[ind])
    {
        ds.push_back(a[ind]);
        combinationalSum(ind,target-a[ind],n,ds,ans,a);
        ds.pop_back();
    }
    combinationalSum(ind+1,target,n,ds,ans,a);
}

int main()
{
    int target=8;
    int a[]={2,1,4,7};
    vector<int> ds;
    int n=3;
    vector<vector<int>> ans;
    combinationalSum(0,target,n,ds,ans,a);
    cout<<"Combinations are:\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"}";
        cout<<endl;
        
    }
}
