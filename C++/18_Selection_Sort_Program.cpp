#include <iostream>

using namespace std;

void selectionSort (int arr[], int arrSize)
{
	int min;
	for (int i = 0; i < arrSize-1; i++)
	{
		min = i;
		
		for (int j = i+1; j < arrSize; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main()
{
	int arrSize;
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];
	
	cout << "Enter " << arrSize << " elements: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}
	
	cout << "UNSORTED array before SELECTION SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// selection sort alogirithm
	selectionSort(arr, arrSize);
	
	cout << "SORTED array after SELECTION SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
