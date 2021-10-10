#include <iostream>

using namespace std;

void shellSort (int arr[], int arrSize)
{
	int temp, i;
	for (int gap = arrSize/2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < arrSize; j++)
		{
			temp = arr[j];
			for (i = j; (i >= gap) && (arr[i-gap] > temp); i -= gap)
			{
				arr[i] = arr[i - gap];
			}
			arr[i] = temp;
		}
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
	
	cout << "UNSORTED array before SHELL SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// SHELL sort alogirithm
	shellSort(arr, arrSize);
	
	cout << "SORTED array after SHELL SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
