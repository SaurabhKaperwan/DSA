#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;
}

void bubbleSort(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {2,3,1,6,7,8,4};
	int size = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr , size);

	cout<<"Sorted Array:\n";
	printArray(arr, size);
}
