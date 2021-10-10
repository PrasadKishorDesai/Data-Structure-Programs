#include <iostream>

using namespace std;

void insertionSort (int arr[], int arrSize)
{
	int key, j;
	for (int i = 1; i < arrSize; i++)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
	}
}

int main()
{
	int arrSize;
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];		// declaring array
	
	// taking input for array
	cout << "Enter " << arrSize << " elements: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}
	
	cout << "UNSORTED array before INSERTION SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// insertion sort alogirithm
	insertionSort(arr, arrSize);
	
	cout << "SORTED array after INSERTION SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
