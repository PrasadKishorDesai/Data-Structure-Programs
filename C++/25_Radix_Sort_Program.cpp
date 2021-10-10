#include <iostream>

using namespace std;

void countSort (int arr[], int arrSize, int div)
{
	int output[arrSize];
	int count[10] = {0};
	
	// counting elements from 0 to 9 from numbers LSB TO MSB
	for (int i = 0; i < arrSize; i++)
	{
		count[ (arr[i]/div)%10 ]++;
	}
	
	// to calculate cummulative count of position of numbers that is from 0 to 9
	for (int i = 1; i < 10; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	
	// assigning element of array to output array according to it's position in count array from last index of array
	for (int i = arrSize-1; i >= 0; i--)
	{
		output[ count[ (arr[i]/div)%10 ] -1 ] = arr[i];
		count[ (arr[i]/div)%10 ]--;
	}
	
	// assigning output array values back to original array
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = output[i];
	}
}

// to get maximum number from the array
int getmax (int arr[], int arrSize)
{
	int max = arr[0];
	for (int i = 1; i < arrSize; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void radixSort (int arr[], int arrSize)
{
	int max = getmax(arr, arrSize);
	
	for (int div = 1; max/div > 0; div *= 10)
	{
		countSort(arr, arrSize, div);
	}
}

int main()
{
	int arrSize;
	int range = 10; 	// range of numbers from 0 to 9 as no of any digit can only vary from 0 to 9
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];		// declaring array
	
	// taking input for array
	cout << "Enter " << arrSize << " elements: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}
	
	cout << "UNSORTED array before RADIX SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// RADIX sort alogirithm
	radixSort(arr, arrSize);
	
	cout << "SORTED array after RADIX SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
