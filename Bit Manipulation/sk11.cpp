//Count no of set bits
#include <iostream>
using namespace std;
//TC(no of bits)
/*
int main()
{
	int n=14;
	int count=0;

	while(n!=0)
	{
		if((n & 1))
			count++;

		n=n>>1;
	}
	cout<<count;
}
*/

//TC:O(no. of set bits)

int main()
{
	int n=14;
	int count=0;

	while(n!=0)
	{
		n=n & (n-1);
		count++;
	}
	cout<<count;
}