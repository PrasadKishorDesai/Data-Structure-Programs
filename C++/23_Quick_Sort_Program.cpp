#include <iostream>

using namespace std;

// partition function
int partition (int arr[], int s, int e)
{
	int pivot = arr[e];					// taking last element as pivot
	int pindex = s;
	int temp;
	
	for (int i = s; i < e; i++)
	{
		// checking if element value is less than pivot
		if (arr[i] <= pivot)
		{
			// placing smaller elements than pivot to left side of array
			temp = arr[pindex];
			arr[pindex] = arr[i];
			arr[i] = temp;
			
			pindex++;
		}
	}
	
	// swapping pivot element to its appropriate position
	temp = arr[pindex];
	arr[pindex] = arr[e];
	arr[e] = temp;
	
	return pindex;
}

// quick sort function
void quickSort (int arr[], int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end);			// to know the pivot position
		quickSort(arr, start, p-1);					// for left sub part of array
		quickSort(arr, p+1, end);					// for right sub part of array
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
	
	cout << "UNSORTED array before QUICK SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// quicksort alogirithm
	quickSort(arr, 0, arrSize-1);
	
	cout << "SORTED array after QUICK SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
