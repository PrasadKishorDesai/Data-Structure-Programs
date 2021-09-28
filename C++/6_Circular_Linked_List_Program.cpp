#include <iostream>

using namespace std;

class Node
{
	public:
		// creating variables
		int key;
		int data;
		Node* next;
		
		// initializing variables
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
		}
};

class CircularLinkedList
{
	public:
		Node* head;
		int count;
		
		// creating constructor for initializing values
		CircularLinkedList ()
		{
			head = NULL;
			count = 0;
		}
		CircularLinkedList (Node *n)
		{
			head = n;
		}
		
		// to check whether a node already exists with key specified
		Node* isNodeExists (int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			
			do
			{
				if (ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			while (ptr->next != head);
			
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
					n->next = head;
					cout << "Node appended at head position" << endl;
				}
				else if (head->next == head)
				{
					head->next = n;
					n->next = head;
					cout << "Node appended" << endl;
				}
				else
				{
					Node* ptr = head->next;
					while (ptr->next != head)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
					n->next = head;
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
				cout << "Node already exists with key: " << n->key << ", try prepending node with another key." << endl;
			}
			else 
			{
				if (head == NULL)
				{
					head = n;
					n->next = head;
					cout << "Node prepended at head position" << endl;
				}
				else 
				{
					Node* ptr = head;
					do 
					{
						ptr = ptr->next;
					}
					while (ptr->next != head);
					
					ptr->next = n;
					n->next = head;
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
					cout << "Node already exists with key: " << n->key << ", try inserting node with another key." << endl;
				}
				else
				{
					if (ptr->next == head)
					{
						ptr->next = n;
						n->next = head;
					}
					else
					{
						n->next = ptr->next;
						ptr->next = n;
					}
					cout << "Node prepended" << endl;
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
				if (head->key == k)
				{
					Node* temp = head;
					do 
					{
						temp = temp->next;
					}
					while (temp->next != head);
					
					head = head->next;
					temp->next = head;
				}
				else if (ptr->next == head)
				{
					Node* temp = head;
					while (temp->next != ptr);
					{
						temp = temp->next;
					}
					temp->next = head;
				}
				else
				{
					Node* temp = head;
					while (temp->next != ptr);
					{
						temp = temp->next;
					}
					temp->next = ptr->next;
				}
				cout << "Node deleted" << endl;
				//delete ptr;
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
				cout << "Circular Linked List is empty!" << endl;
			}
			else
			{
				Node* ptr = head;
				cout << "Nodes in Circular Linked List are: " << endl;
				cout << "Address of head node is: " << head << endl;
				do 
				{
					cout << "(" << ptr->key << ", " << ptr->data << ", " << ptr->next << ") ---> ";
				}
				while (ptr->next != head);
			}
			cout << endl;
		}
};

int main()
{
	CircularLinkedList c;
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
				c.appendNode(n1);
				break;
				
			case 2:
				cout << "Enter key and data of node you want to prepend: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				c.prependNode(n1);
				break;
				
			case 3:
				cout << "Enter key of node after which you want to insert node: ";
				cin >> k1;
				cout << "Enter key and data of node you want to insert: ";
				cin >> key1 >> data1;
				n1->key = key1;
				n1->data = data1;
				c.insertNode(n1, k1);
				break;
				
			case 4:
				cout << "Enter key of node you want to delete: ";
				cin >> key1;
				c.deleteNode(key1);
				break;
				
			case 5:
				ans = c.countOfNodes();
				cout << "Count of nodes in Singly Linked List is: " << ans << endl;
				break;
				
			case 6:
				cout << "Ente key of node you want to update: ";
				cin >> key1;
				cout << "Ente value of node you want to update: ";
				cin >> data1;
				c.update(key1, data1);
				break;
				
			case 7:
				c.display();
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
