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

class CircularQueue
{
	public:
		Node* front;
		Node* rear;
		
		CircularQueue ()
		{
			front = NULL;
			rear = NULL;
		}
		
		// to ckeck whether node exists or not in queue
		bool isNodeExists (Node *n)
		{
			bool exists = false;
			Node* temp = front;
			do
			{
				if (temp->key == n->key)
				{
					exists = true;
					break;
				}
				temp = temp->next;
			}
			while (temp != front);
			
			return exists;
		}
		
		// to ckeck whether queue is empty or not
		bool isEmpty ()
		{
			if (front == NULL && rear == NULL)
				return true;
			else
				return false;
		}
		
		// to add elements in queue
		void enqueue (Node *n)
		{
			if (isEmpty())
			{
				front = n;
				rear = n;
				n->next = front;					// made changes
				cout << "Node ENQUEUED" << endl;
			}
			else if (isNodeExists(n))
			{
				cout << "Node already exists with key: " << n->key << ", try enqueing node with another key" << endl;
			}
			else
			{
				rear->next = n;
				rear = n;
				n->next = front;					// made changes
				cout << "Node ENQUEUED" << endl;
			}
		}
		
		// to remove elements from queue
		void dequeue ()
		{
			if (isEmpty())
			{
				cout << "Queue underflow" << endl;
			}
			else if (front == rear)
			{
				Node* temp = front;
				front = NULL;
				rear = NULL;
				delete temp;
				cout << "Node DEQUEUED" << endl;
			}
			else
			{
				Node* temp = front;
				front = front->next;
				rear->next = front;					// made changes
				delete temp;
				cout << "Node DEQUEUED" << endl;
			}
		}
		
		// to count number of elements
		int count ()
		{
			if (isEmpty())
			{
				cout << "Queue is empty" << endl;
				return 0;
			}
			else
			{
				Node* temp = front;
				int count = 0;
				do
				{
					count++;
					temp = temp->next;
				}
				while (temp != front);
				
				return count;
			}
		}
		
		// to display queue
		void display ()
		{
			if (isEmpty())
			{
				cout << "Queue is empty" << endl;
			}
			else
			{
				Node* temp = front;
				cout << "Address of front node: " << front << endl;
				do
				{
					cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ") ---> ";
					temp = temp->next;
				}
				while (temp != front);
			}
		}
};

int main()
{
	CircularQueue c;
	int choice, key1, data1, ans;
	
	do
	{
		cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> enqueue()" << endl;
		cout << "2 -> dequeue()" << endl;
		cout << "3 -> isEmpty()" << endl;
		cout << "4 -> count()" << endl;
		cout << "5 -> display()" << endl;
		cout << "6 -> clear screen" << endl;
		
		cin >> choice;
		
		Node* n1 = new Node();
		
		switch (choice)
		{
			case 0:
				cout << "Exiting program...!\nThank you!" << endl;
				delete[] n1;
				break;
				
			case 1:
				cout << "Enter key and data of node you want to enqueue: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				c.enqueue(n1);
				break;
				
			case 2:
				c.dequeue();
				break;
				
			case 3:
				if (c.isEmpty())
					cout << "Queue is empty" << endl;
				else
					cout << "Queue is not empty" << endl;
				break;
				
			case 4:
				ans = c.count();
				cout << "Count of elements in queue are: " << ans << endl;
				break;
			
			case 5:
				c.display();
				break;
				
			case 6:
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
