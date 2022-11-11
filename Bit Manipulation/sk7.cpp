//set ith bit
//TC:O(1)
#include <iostream>
using namespace std;
int main()
{
	int n=13;
	int i=1;

	int mask=1<<i;

	n= n | mask;
	
	cout<<n;
}