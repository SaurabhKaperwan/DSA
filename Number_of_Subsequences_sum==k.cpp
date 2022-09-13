//Print Number of Subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;

int subseq(int ind,int a[],int n,int sum,int s)
{
    if(ind==n)
    {
        if(s == sum)
        {
            return 1;
        }
        return 0;
    }
    
    s+=a[ind];
    int l=subseq(ind+1,a,n,sum,s);

    s-=a[ind];
    int r=subseq(ind+1,a,n,sum,s);
    return l+r;
}

int main()
{
    int a[]={1,2,1};
    int n=3;
    int sum = 3;
    cout<<subseq(0,a,n,sum,0);
    return 0;
}
