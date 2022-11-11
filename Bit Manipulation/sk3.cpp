//Print XOR of all no b/w 1 to N
//TC : O(1)
#include <iostream>
using namespace std;
int main()
{
	int i=25;

	if(i%4==0)
		cout<<i<<" ";
	if(i%4==1)
		cout<<1<<" ";
	if(i%4==2)
		cout<<i+1<<" ";
	if(i%4==3)
		cout<<0<<" ";
}