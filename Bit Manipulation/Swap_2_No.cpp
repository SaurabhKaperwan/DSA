//Swap 2 nos
#include <iostream>
using namespace std;
int main()
{
	int a=5,b=7;
	a=a xor b;
	b=a xor b;
	a=a xor b;
	cout<<"a:"<<a<<" "<<"b:"<<b; 	
}
