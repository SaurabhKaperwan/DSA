#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &maxHeap ,int i)
{
	int size = maxHeap.size();
	int maxi = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < size && maxHeap[l] > maxHeap[maxi])
		maxi = l;

	if(r < size && maxHeap[r] > maxHeap[maxi])
		maxi = r;

	if(maxi != i)
	{
		swap(maxHeap[maxi],maxHeap[i]);
		heapify(maxHeap,maxi);
	}
}

void swap(int &a , int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(vector<int> &maxHeap)
{
	for(int i = 0 ; i < maxHeap.size() ; i++)
		cout<<maxHeap[i]<<" ";
	cout<<endl;
}

void insert(vector<int> &maxHeap , int num)
{
	if(maxHeap.size() == 0)
	{
		maxHeap.push_back(num);
	}

	else
	{
		maxHeap.push_back(num);

		for(int i = maxHeap.size() / 2 - 1; i >= 0; i--)
		{
			heapify(maxHeap,i);
		}
	}
}

void deleteNode(vector<int> &maxHeap,int num)
{
	int size = maxHeap.size();
	int i;
	for(i = 0; i < size ; i++)
	{
		if(num == maxHeap[i])
			break;
	}
	swap(maxHeap[i],maxHeap[size-1]);
	maxHeap.pop_back();

	for(int i = size / 2 - 1 ; i >= 0 ; i--)
	{
		heapify(maxHeap,i);
	}
}

int peek(vector<int> &maxHeap)
{
	return maxHeap[0];
}

void extractMax(vector<int> &maxHeap)
{
	int size = maxHeap.size();
	swap(maxHeap[0],maxHeap[size-1]);
	maxHeap.pop_back();

	heapify(maxHeap,0);
}


int main()
{
	vector<int> maxHeap;

	insert(maxHeap,3);
	insert(maxHeap,4);
	insert(maxHeap,9);
	insert(maxHeap,5);
	insert(maxHeap,2);

	cout<<"Max Heap: ";
	print(maxHeap);

	deleteNode(maxHeap,5);
	cout<<"Max Heap: ";
	print(maxHeap);

	extractMax(maxHeap);
	cout<<"Max Heap: ";
	print(maxHeap);
}