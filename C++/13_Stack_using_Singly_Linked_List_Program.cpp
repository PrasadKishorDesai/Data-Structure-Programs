#include <iostream>

using namespace std;

// creating node class
class Node
{
	public:
		// declaring variables and initializing in constructor
		int key;
		int data;
		Node* next;
		
		Node ()
		{
			key = 0;
			data = 0;
			next = NULL;
		}
		Node (int k, int d)
		{
			key = k;
			data = d;
			next = NULL;
		}
};

class Stack
{
	public:
		Node* top;
		
		Stack ()
		{
			top = NULL;
		}
		
		// to ckeck whether node already exists or not in stack
		bool isNodeExists (Node *n)
		{
			bool exists = false;
			Node* temp = top;
			while (temp != NULL)
			{
				if (temp->key == n->key)
				{
					exists = true;
					break;
				}
				temp = temp->next;
			}
			return exists;
		}
		
		// to ckeck whether stack is empty or not
		bool isEmpty ()
		{
			if (top == NULL)
				return true;
			else
				return false;
		}
		
		// to add elements into stack
		void push (Node *n)
		{
			if (top == NULL)
			{
				top = n;
				cout << "Node PUSHED on stack" << endl;
			}
			else if (isNodeExists(n))
			{
				cout << "Node already exists with key: " << n->key << ", try pushing node with another key" << endl;
			}
			else
			{
				n->next = top;
				top = n;
				cout << "Node PUSHED on stack" << endl;
			}
		}
		
		// to remove elements from stack
		void pop ()
		{
			if (isEmpty())
			{
				cout << "Stack underflow" << endl;
			}
			else
			{
				Node* temp = top;
				top = top->next;
				delete temp;
				cout << "Node POPPED from stack" << endl;
			}
		}
		
		// to return count of elements
		int count ()
		{
			Node* temp = top;
			int count = 0;
			while (temp != NULL)
			{
				count++;
				temp = temp->next;
			}
			return count;
		}
		
		// to return top of stack
		Node* peek ()
		{
			return top;
		}
		
		// to display stack
		void display()
		{
			if (isEmpty())
			{
				cout << "Stack is empty" << endl;
			}
			else
			{
				Node* temp = top;
				while (temp != NULL)
				{
					cout << "(" << temp->key << ", " << temp->data << ") --->" << endl;
					temp = temp->next;
				}
			}
		}
};

int main()
{
	Stack s;
	int choice, key1, data1, ans;
	
	do
	{
		cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> push()" << endl;
		cout << "2 -> pop()" << endl;
		cout << "3 -> isEmpty()" << endl;
		cout << "4 -> count()" << endl;
		cout << "5 -> peek()" << endl;
		cout << "6 -> display()" << endl;
		cout << "7 -> clear screen" << endl;
		
		cin >> choice;
		
		Node* n1 = new Node();
		
		switch (choice)
		{
			case 0:
				cout << "Exiting program...!\nThank you!" << endl;
				delete[] n1;
				break;
				
			case 1:
				cout << "Enter key and data of node you want to push: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				s.push(n1);
				break;
				
			case 2:
				s.pop();
				break;
				
			case 3:
				if (s.isEmpty())
					cout << "Stack is empty" << endl;
				else
					cout << "Stack is not empty" << endl;
				break;
				
			case 4:
				ans = s.count();
				cout << "Count of elements in stack are: " << ans << endl;
				break;
				
			case 5:
				n1 = s.peek();
				cout << "Key of top node is: " << n1->key << " and data is: " << n1->data << endl;
				break;
			
			case 6:
				s.display();
				break;
				
			case 7:
				system("cls");
				break;
				
			default:
				cout << "Enter valid choice...!!" << endl;
		}
		cout << endl;
	}
	while (choice != 0);
	
	return 0;
}
