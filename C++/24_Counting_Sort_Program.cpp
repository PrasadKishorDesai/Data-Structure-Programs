#include <iostream>

using namespace std;

void countSort (int arr[], int arrSize, int range)
{
	int output[arrSize];			// output array of size of input array
	int count[range] = {0};			// count array of size of range that is from 0 to 9
	
	// for counting the count of numbers in array
	for (int i = 0; i < arrSize; i++)
	{
		++count[arr[i]];
	}
	
	// to calculate cummulative count of position of numbers
	for (int i = 1; i < range; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	
	// assigning element of array to output array according to it's position in count array
	for (int i = 0; i < arrSize; i++)
	{
		output[--count[arr[i]]] = arr[i];
	}
	
	// assigning output array values back to original array
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = output[i];
	}
}

int main()
{
	int arrSize;
	int range = 10; 	// range of numbers from 0 to 9; for simplicity we are hard coiding it
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];		// declaring array
	
	// taking input for array
	cout << "Enter " << arrSize << " elements: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}
	
	cout << "UNSORTED array before COUNT SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// COUNT sort alogirithm
	countSort(arr, arrSize, range);
	
	cout << "SORTED array after COUNT SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
