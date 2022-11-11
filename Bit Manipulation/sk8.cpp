//clear ith bit
//TC:O(1)
#include <iostream>
using namespace std;
int main()
{
	int n=13;
	int i=2;

	int mask=1<<i;
	mask=~mask;

	n= n & mask;
	
	cout<<n;
}