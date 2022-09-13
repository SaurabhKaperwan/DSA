//Printing Subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;

bool subseq(int ind,int a[],int n,int sum,vector<int> &ds,int s)
{
    if(ind==n)
    {
        if(s == sum)
        {
            cout<<"{";
            for(auto itr : ds)
            {
                cout<<itr<<" ";
            }
            cout<<"}"<<endl;
            return true;
        }
        return false;
    }
    
    ds.push_back(a[ind]);
    s+=a[ind];
    if(subseq(ind+1,a,n,sum,ds,s)==true)
    {
        return true;
    }

    s-=a[ind];
    ds.pop_back();
    if(subseq(ind+1,a,n,sum,ds,s))
    {
        return true;
    }
    return false;
}

int main()
{
    int a[]={1,2,1};
    int n=3;
    vector<int> ds;
    int sum = 3;
    subseq(0,a,n,sum,ds,0);
    return 0;
}
