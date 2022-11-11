//Given a range (L-R),print the XOR
//Print XOR of all no b/w 1 to N
#include <iostream>
using namespace std;
int findXOR(int i)
{
	if(i%4==0)
		return i;
	if(i%4==1)
		return 1;
	if(i%4==2)
		return i+1;
	return 0;
}
int main()
{
	int l=3,h=6;
	int ans=findXOR(h)^findXOR(l-1);
	cout<<ans;
}