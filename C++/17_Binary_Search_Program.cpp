#include <iostream>

using namespace std;

int binary_search (int arr[], int arrSize, int num)
{
	int left = 0;
	int right = arrSize;
	int mid;
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (arr[mid] == num)
		{
			return mid;
		}
		else if (num > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int num;
	int arrSize;
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];
	
	cout << "Enter " << arrSize << " elements in ASCENDING order: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Enter number you want to search in the array: ";
	cin >> num;
	
	int output = binary_search(arr, arrSize, num);
	
	if (output == -1)
	{
		cout << "Element NOT found" << endl;
	}
	else
	{
		cout << "Element found at position: " << output + 1 << endl;
	}
	
	return 0;
}
