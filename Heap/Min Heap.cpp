#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &minHeap ,int i)
{
	int size = minHeap.size();
	int mini = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < size && minHeap[l] < minHeap[mini])
		mini = l;

	if(r < size && minHeap[r] < minHeap[mini])
		mini = r;

	if(mini != i)
	{
		swap(minHeap[mini],minHeap[i]);
		heapify(minHeap,mini);
	}
}

void swap(int &a , int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(vector<int> &minHeap)
{
	for(int i = 0 ; i < minHeap.size() ; i++)
		cout<<minHeap[i]<<" ";
	cout<<endl;
}

void insert(vector<int> &minHeap , int num)
{
	if(minHeap.size() == 0)
	{
		minHeap.push_back(num);
	}

	else
	{
		minHeap.push_back(num);

		for(int i = minHeap.size() / 2 - 1; i >= 0; i--)
		{
			heapify(minHeap,i);
		}
	}
}

void deleteNode(vector<int> &minHeap,int num)
{
	int size = minHeap.size();
	int i;
	for(i = 0; i < size ; i++)
	{
		if(num == minHeap[i])
			break;
	}
	swap(minHeap[i],minHeap[size-1]);
	minHeap.pop_back();

	for(int i = size / 2 - 1 ; i >= 0 ; i--)
	{
		heapify(minHeap,i);
	}
}

int peek(vector<int> &minHeap)
{
	return minHeap[0];
}

void extractMax(vector<int> &minHeap)
{
	int size = minHeap.size();
	swap(minHeap[0],minHeap[size-1]);
	minHeap.pop_back();

	heapify(minHeap,0);
}


int main()
{
	vector<int> minHeap;

	insert(minHeap,3);
	insert(minHeap,4);
	insert(minHeap,9);
	insert(minHeap,5);
	insert(minHeap,2);

	cout<<"Min Heap: ";
	print(minHeap);

	deleteNode(minHeap,5);
	cout<<"Min Heap: ";
	print(minHeap);

	extractMax(minHeap);
	cout<<"Min Heap: ";
	print(minHeap);
}