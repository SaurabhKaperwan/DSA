//Check whether ith bit is set or not
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n=13;
	int i=1;
	//int p=pow(2,double(i));
	int p=1<<i;
	if((n & p) == 0) 
		cout<<"Not set";
	else
		cout<<"Set";
}