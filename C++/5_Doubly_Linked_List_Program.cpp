#include <iostream>

using namespace std;

class Node
{
	public:
		// creating variables
		int key;
		int data;
		Node* next;
		Node* previous;
		
		// initializing variables
		Node ()
		{
			key = 0;
			data = 0;
			next = NULL;
			previous = NULL;
		}
		
		Node (int k, int d)
		{
			key = k;
			data = d;
		}
};

class DoublyLinkedList
{
	public:
		Node* head;
		int count;
		
		// creating constructor for initializing values
		DoublyLinkedList ()
		{
			head = NULL;
			count = 0;
		}
		DoublyLinkedList (Node *n)
		{
			head = n;
		}
		
		// to check whether a node already exists with key specified
		Node* isNodeExists (int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			
			while (ptr != NULL)
			{
				if (ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		//  to add node at end of list
		void appendNode (Node *n)
		{
			if (isNodeExists(n->key) != NULL)
			{
				cout << "Node already exists with key: " << n->key << ", try appending node with another key." << endl;
			}
			else
			{
				if (head == NULL)
				{
					head = n;
					cout << "Node appended at head position" << endl;
				}
				else
				{
					Node* ptr = head;
					while (ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
					n->previous = ptr;
					cout << "Node appended" << endl;
				}
				count++;
			}
		}
		
		// to add node to beginning of list
		void prependNode (Node *n)
		{
			if (isNodeExists(n->key) != NULL)
			{
				cout << "Node already exists with key: " << n->key << ", try appending node with another key." << endl;
			}
			else 
			{
				if (head == NULL)
				{
					head = n;
					cout << "Node prepended at head position" << endl;
				}
				else
				{
					n->next = head;
					head->previous = n;
					head = n;
					cout << "Node prepended" << endl;
				}
				count++;
			}
		}
		
		// to insert node after specific position of node with key value k
		void insertNode (Node *n, int k)
		{
			Node* ptr = isNodeExists(k);
			if (ptr == NULL)
			{
				cout << "Node does not exists with key: " << k << endl;
			}
			else
			{
				if (isNodeExists(n->key) != NULL)
				{
					cout << "Node already exists with key: " << n->key << ", try appending node with another key." << endl;
				}
				else
				{
					if ((head->next == NULL) && (head->key == k))
					{
						head->next = n;
						n->previous = head;
					}
					else if (ptr->next == NULL)
					{
						ptr->next = n;
						n->previous = ptr;
					}
					else
					{
						n->next = ptr->next;
						n->previous = ptr;
						ptr->next->previous = n;
						ptr->next = n;
					}
					cout << "Node inserted" << endl;
					count++;
				}
			}
		}
		
		// to delete a node by specific key
		void deleteNode (int k)
		{
			Node* ptr = isNodeExists(k);
			if (ptr == NULL)
			{
				cout << "Node does not exists with key: " << k << endl;
			}
			else
			{
				if (ptr == head)
				{
					head = ptr->next;
					head->previous = NULL;
				}
				else if (ptr->next == NULL)
				{
					ptr->previous->next = NULL;
				}
				else
				{
					ptr->previous->next = ptr->next;
					ptr->next->previous = ptr->previous;
				}
				delete ptr;
				cout << "Node deleted" << endl;
				count--;
			}
		}
		
		// to return count of elements(nodes) in list
		int countOfNodes ()
		{
			return count;
		}
		
		// to change the data value
		void update (int k, int d)
		{
			Node* ptr = isNodeExists(k);
			if (ptr == NULL)
			{
				cout << "Node does not exists with key: " << k << endl;
			}
			else
			{
				ptr->data = d;
				cout << "Node updated" << endl;
			}
		}
		
		// to display singly linked list
		void display()
		{
			if (head == NULL)
			{
				cout << "Doubly Linked List is empty!" << endl;
			}
			else
			{
				Node* ptr = head;
				cout << "Nodes in Doubly Linked List are: " << endl;
				while (ptr != NULL)
				{
					cout << "(" << ptr->key << ", " << ptr->data << ") ---> ";
					ptr = ptr->next;
				}
				cout << endl;
			}
		}
};

int main()
{
	DoublyLinkedList d;
	int key1, data1, k1, choice, ans;
	
	do
	{
		cout << "Enter your choice: " << endl;
		cout << "0 -> exit" << endl;
		cout << "1 -> appendNode()" << endl;
		cout << "2 -> prependNode()" << endl;
		cout << "3 -> insertNode()" << endl;
		cout << "4 -> deleteNode()" << endl;
		cout << "5 -> countOfNodes()" << endl;
		cout << "6 -> update()" << endl;
		cout << "7 -> display()" << endl;
		cout << "8 -> clear screen()" << endl;
		
		cin >> choice;
		
		// dynamic memory allocation
		Node* n1 = new Node();
		
		switch (choice)
		{
			case 0:
				cout << "Exiting program...!\nThank you!" << endl;
				break;
				
			case 1:
				cout << "Enter key and data of node you want to append: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				d.appendNode(n1);
				break;
				
			case 2:
				cout << "Enter key and data of node you want to prepend: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				d.prependNode(n1);
				break;
				
			case 3:
				cout << "Enter key of node after which you want to insert node: ";
				cin >> k1;
				cout << "Enter key and data of node you want to insert: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				d.insertNode(n1, k1);
				break;
				
			case 4:
				cout << "Enter key of node you want to delete: ";
				cin >> key1;
				d.deleteNode(key1);
				break;
				
			case 5:
				ans = d.countOfNodes();
				cout << "Count of nodes in Singly Linked List is: " << ans << endl;
				break;
				
			case 6:
				cout << "Ente key of node you want to update: ";
				cin >> key1;
				cout << "Ente value of node you want to update: ";
				cin >> data1;
				d.update(key1, data1);
				break;
				
			case 7:
				d.display();
				break;
				
			case 8:
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
