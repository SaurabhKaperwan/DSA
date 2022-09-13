//Printing Subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;

void subseq(int ind,int a[],int n,int sum,vector<int> &ds,int s)
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
        }
        return;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    subseq(ind+1,a,n,sum,ds,s);

    s-=a[ind];
    ds.pop_back();
    subseq(ind+1,a,n,sum,ds,s);

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
