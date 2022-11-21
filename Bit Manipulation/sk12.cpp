//Find the two no which does not have pair
//TC:O(N)
//SC:O(1)

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={2,1,2,5,1,4,4,7,3,3};
	int XOR=0;
	int size=sizeof(a)/sizeof(int);
	for(int i=0;i<size;i++)
	{
		XOR=XOR ^ a[i];
	}

	int cnt=0;

	while(XOR)
	{
		if(XOR & 1)
			break;
		cnt++;

		XOR=XOR>>1;
	}

	int XOR1=0,XOR2=0;

	for(int i=0;i<size;i++)
	{
		if(a[i]&(1<<cnt))
			XOR1=XOR1^a[i];
		else
			XOR2=XOR2^a[i];
	}
	cout<<"Both nos:"<<XOR1<<" "<<XOR2;

	return 0;
}