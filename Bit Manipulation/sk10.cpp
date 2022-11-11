//Check if a no. is power of 2
//TC:O(N)
#include <iostream>
using namespace std;
int main()
{
	int n=8;
	if(!(n & (n-1)))
		cout<<"Yes";
	else
		cout<<"No";
}