#include <iostream>

using namespace std;

void linear_search (int a[], int arrSize, int num)
{
	int flag = 1;
	for (int i = 0; i<arrSize; i++)
	{
		if (a[i] == num)
			cout << "Number founded at position: " << i+1 << endl;
			flag = 0;
	}
	if (flag)
	{
		cout << "Number not found in array" << endl;
	}
}

int main()
{
	int arrSize;
	
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];
	
	cout << "Enter " << arrSize << " elements of array: " << endl;
	for (int i = 0; i < arrSize; i++) 
	{
		cin >> arr[i];
	}
	
	int num;
	cout << "Enter number you want to search in array: ";
	cin >> num;
	
	linear_search(arr, arrSize, num);
	
	return 0;
}
