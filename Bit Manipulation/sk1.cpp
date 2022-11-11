//Print the no. which is not in pair
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={2,1,2,5,6,5,7,7,6};
	int XOR=0;

	for (int i = 0; i < 9; ++i)
	{
		XOR^=a[i];
	}
	cout<<XOR;

}
