#include <iostream>

using namespace std;

class Stack 
{
	private:
		// declaring variables
		int *arr;
		int arrSize, top;
		
	public:
		// initializing variables and array (dynamic memory allocation) 
		Stack () 
		{
			cout << "Enter size of stack: ";
			cin >> arrSize;
			arr = new int[arrSize];
			for (int i = 0; i < arrSize; i++)
			{
				arr[i] = 0;
			}
			top = -1;
		}
		
		// check whether stack is empty
		bool isEmpty ()
		{
			if (top == -1)
				return true;
			return false;
		}
		// check whether stack is full
		bool isFull ()
		{
			if ((top + 1) == arrSize)
				return true;
			return false;
		}
		
		// push element on stack
		void push (int elem)
		{
			if (isFull())
			{
				cout << "Stack is already full, cannot add element!" << endl;
			}
			else
			{
				top++;
				arr[top] = elem;
				cout << "Element pushed on stack" << endl;
			}
		}
		
		// pop element from stack
		void pop()
		{
			if (isEmpty())
			{
				cout << "Stack is already empty, cannot remove element!" << endl;
			}
			else
			{
				int elem = arr[top];
				arr[top] = 0;
				top--;
				cout << "Element popped\nValue of popped element is: " << elem << endl;
			}
		}
		
		// return count of elements
		int count ()
		{
			return (top + 1);
		}
		
		// access element at certain position
		void peek (int position)
		{
			if (isEmpty())
				cout << "Stack is empty" << endl;
			else if (position > arrSize || position <= -1)
				cout << "Enter valid position between 1 and " << arrSize << endl;
			else
				cout << "Value at position " << position << " is: " << arr[position-1] << endl;
		}
		
		// changes element at specified index
		void change (int index, int element)
		{
			if (isEmpty())
				cout << "Stack is empty" << endl;
			else if (index >= arrSize || index <= -1)
				cout << "Enter valid index between 0 and " << arrSize-1 << endl;
			else
			{
				arr[index] = element;
				cout << "Element changed at index " << index << endl;
			}
		}
		
		// to display stack
		void display ()
		{
			cout << "Elements of stack are: \n" << endl;
			for (int i = arrSize-1; i >= 0; i--)
			{
				cout << "|     " << arr[i] << "     |" << endl;
				cout << "-------------" << endl;
			}
		}
		
		// to free the space
		void clear ()
		{
			delete[] arr;
		}
};

int main()
{
	Stack s;
	int choice, index, element, ans;
	
	do
	{
		cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> push()" << endl;
		cout << "2 -> pop()" << endl;
		cout << "3 -> isFull()" << endl;
		cout << "4 -> isEmpty()" << endl;
		cout << "5 -> peek()" << endl;
		cout << "6 -> count()" << endl;
		cout << "7 -> change()" << endl;
		cout << "8 -> display()" << endl;
		cout << "9 -> clear screen" << endl;
		
		cin >> choice;
		
		switch (choice)
		{
			case 0:
				s.clear();
				cout << "Exiting program...!\nThank you!" << endl;
				break;
				
			case 1:
				cout << "Enter element you want to push: ";
				cin >> element;
				s.push(element);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
				if (s.isFull())
					cout << "Stack is Full" << endl;
				else
					cout << "Stack is not Full" << endl;
				break;
				
			case 4:
				if (s.isEmpty())
					cout << "Stack is Empty" << endl;
				else
					cout << "Stack is not Empty" << endl;
				break;
				
			case 5:
				cout << "Enter at which position you want to access element: ";
				cin >> index;
				s.peek(index);
				break;
				
			case 6:
				ans = s.count();
				cout << "Count of elements in stack is: " << ans << endl;
				break;
				
			case 7:
				cout << "Enter index at which you want to change element: ";
				cin >> index;
				cout << "Enter value you want to change: ";
				cin >> element;
				s.change(index, element);
				break;
				
			case 8:
				s.display();
				break;
				
			case 9:
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
