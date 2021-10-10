#include <iostream>

using namespace std;

// merge function
void merge (int arr[], int l, int m, int r)
{
	int i = l;						// to track position of left sub array
	int j = m+1;					// to track position of right sub array
	int k = l;						// to track position of temp array
	int temp[r];
	
	// to compare values between left and right sub arrays
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	
	// to add remaining values from left sub array
	while (i <= m)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	// to add remaining values from right sub array
	while (j <= r)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	// to copy values from temp array to real array
	for (int s = l; s <= r; s++)
	{
		arr[s] = temp[s];
	}
}

// mergesort function
void mergeSort (int arr[], int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;			// to find middle value
		mergeSort(arr, l, m);		// for left sub part of array
		mergeSort(arr, m+1, r);		// for right sub part of array
		merge(arr, l, m, r);		// to merge the 2 sub arrays
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
	
	cout << "UNSORTED array before MERGE SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// mergesort alogirithm
	mergeSort(arr, 0, arrSize-1);
	
	cout << "SORTED array after MERGE SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
