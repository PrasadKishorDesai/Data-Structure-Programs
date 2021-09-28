#include <iostream>

using namespace std;

class CircularQueue
{
	// declaring variables
	private:
		int front, rear, count;
		int *arr;
		int arrSize;
		
	public:
		// initializing variables and arr (dynamic memory allocation) using default constructor
		CircularQueue () 
		{
			front = -1;
			rear = -1;
			count = 0;
			cout << "Enter size of queue: ";
			cin >> arrSize;
			
			arr = new int[arrSize];
			for (int i = 0; i < arrSize; i++)
			{
				arr[i] = 0;
			}
		}
		
		// check whether queue is empty
		bool isEmpty ()
		{
			if (front == -1 && rear == -1)
				return true;
			return false;
		}
		// check whether queue is full
		bool isFull ()
		{
			if ((rear + 1)%arrSize == front) 		// updated condition for Circular Queue
				return true;
			return false;
		}
		
		// to push(enqueue) element on queue
		void enqueue (int elem)
		{
			if (isFull())
			{
				cout << "Queue is already full, cannot add element to it" << endl;
				return;
			}
			else if (isEmpty())
			{
				front = 0;
				rear = 0;
				arr[front] = elem;
			}
			else
			{
				rear = (rear + 1) % arrSize; 		// updated condition for Circular Queue
				arr[rear] = elem;
			}
			cout << "Element enqueued" << endl;
			count++;
		}
		
		// to remove(dequeue) element from queue
		void dequeue ()
		{
			if (isEmpty())
			{
				cout << "Queue is already empty, cannot remove element from it" << endl;
				return;
			}
			// the below condition will only satisfy when there is only one element in queue
			else if (front == rear)
			{
				int elem = arr[front];
				arr[front] = 0;
				front = -1;
				rear = -1;
				cout << "Element removed from the queue is: " << elem << endl;
			}
			else
			{
				int elem = arr[front];
				arr[front] = 0;
				front = (front + 1) % arrSize; 		// updated condition for Circular Queue
				cout << "Element removed from the queue is: " << elem << endl;
			}
			count--;
		}
		
		// to give count of elements
		int countOfElements ()
		{
			return count;
		}
		
		// to display queue
		void display ()
		{
			cout << "Elements in Queue are: " << endl;
			for (int i = 0; i < arrSize; i++)
			{
				cout << "|     " << arr[i] << "     ";
			}
			cout << "|" << endl;
		}
		
		// to free the allocated space
		void clear ()
		{
			delete[] arr;
		}
};

int main()
{
	CircularQueue c;
	int choice, index, element, ans;
	
	do
	{
		cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> enqueue()" << endl;
		cout << "2 -> dequeue()" << endl;
		cout << "3 -> isFull()" << endl;
		cout << "4 -> isEmpty()" << endl;
		cout << "5 -> countOfElements()" << endl;
		cout << "6 -> display()" << endl;
		cout << "7 -> clear screen" << endl;
		
		cin >> choice;
		
		switch (choice)
		{
			case 0:
				c.clear();
				cout << "Exiting program...!\nThank you!" << endl;
				break;
				
			case 1:
				cout << "Enter element you want to enqueue: ";
				cin >> element;
				c.enqueue(element);
				break;
				
			case 2:
				c.dequeue();
				break;
				
			case 3:
				if (c.isFull())
					cout << "Queue is Full" << endl;
				else
					cout << "Queue is not Full" << endl;
				break;
				
			case 4:
				if (c.isEmpty())
					cout << "Queue is Empty" << endl;
				else
					cout << "Queue is not Empty" << endl;
				break;
				
			case 5:
				ans = c.countOfElements();
				cout << "Count of elements in Queue is: " << ans << endl;
				break;
				
			case 6:
				c.display();
				break;
				
			case 7:
				system("cls");
				break;
				
			default:
				cout << "Enter valid choice!" << endl;
		}
		cout << endl;
	}
	while (choice != 0);
	
	return 0;
}
