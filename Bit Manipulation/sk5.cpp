//Check whether N is even or odd
#include <iostream>
using namespace std;
int main()
{
	int n=23;
	if((n & 1) != 0)//Faster than modulus and division opr
		cout<<"Odd";
	else
		cout<<"Even";
}