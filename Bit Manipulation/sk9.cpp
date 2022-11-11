//Remove the last set bit
#include <iostream>
using namespace std;
int main()
{
	int n=12;
	n= n & (n-1);
	
	cout<<n;
}