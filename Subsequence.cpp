//Print the Subsequences 
//TC=2^n
//SC=n
#include<bits/stdc++.h>
using namespace std;

void subseq(int ind,vector<int> &ds,int arr[],int n)
{
    if(ind == n)
    {
        cout<<"{";
        for(auto it : ds)
            cout<<it<<" ";
        cout<<"}";
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    subseq(ind+1,ds,arr,n);
    ds.pop_back();
    subseq(ind+1,ds,arr,n);
}

int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    subseq(0,ds,arr,n);
    return 0;
}
