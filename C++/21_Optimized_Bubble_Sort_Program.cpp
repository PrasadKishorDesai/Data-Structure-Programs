#include <iostream>

using namespace std;

void bubbleSort (int arr[], int arrSize)
{
	int temp, count;
	bool flag;
	
	for (int i = 0; i < arrSize-1; i++)
	{
		flag = false;
		for (int j = 0; j < arrSize-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				flag = true;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		count++;
		
		if (flag == false)
			break;
	}
	cout << "Count of loops: " << count << endl;
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
	
	cout << "UNSORTED array before BUBBLE SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	
	// bubble sort alogirithm
	bubbleSort(arr, arrSize);
	
	cout << "SORTED array after BUBBLE SORT: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	}
	
	return 0;
}
