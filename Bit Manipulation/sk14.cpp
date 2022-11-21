//Generate all the subsets
//Power Set Algorithm
//TC: O(N*2^N)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={3,2,4,5,6};
	int size=sizeof(a)/sizeof(int);
	cout<<"All the subset:\n";
	for(int num=0;num<pow(2,size);num++)
	{
		vector<int> ds;
		for(int bit=0;bit<size;bit++)
		{
			if(num & (1<<bit))
				ds.push_back(a[bit]);
		}
		for(auto itr : ds)
			cout<<itr<<" ";
		cout<<endl;		
	}

}