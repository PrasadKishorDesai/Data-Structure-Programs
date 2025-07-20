package Java;

import java.util.Scanner;

class Node {

    int key;
    int val;
    Node next;

    Node() {
        key = 0;
        val = 0;
        next = null;
    }

    Node(int key, int val) {
        this.key = key;
        this.val = val;
        next = null;
    }
}

class SinglyLinkedList {

    Node head;
    int count;

    SinglyLinkedList() {
        head = null;
        count = 0;
    }

    SinglyLinkedList(Node n) {
        head = n;
    }

    Node isNodeExists(int key) {
        Node temp = head;
        while (temp != null) {
            if (temp.key == key) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }

    void appendNode(Node n) {
        if (head == null) {
            head = n;
            System.out.println("Node appended at head position");
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = n;
            System.out.println("Node appended");
        }
        count++;
    }

    void prependNode(Node n) {
        if (head == null) {
            head = n;
            System.out.println("Node prepended at head position");
        } else {
            n.next = head;
            head = n;
            System.out.println("Node prepended");
        }
        count++;
    }

    void insertNode(Node n, int key) {
        Node temp = isNodeExists(key);
        if (temp == null) {
            System.out.println("Node do not exists with key: " + key);
        } else {
            n.next = temp.next;
            temp.next = n;
            count++;
            System.out.println("Node inserted");
        }
    }

    void deleteNode(int key) {
        Node temp = isNodeExists(key);
        if (temp == null) {
            System.out.println("Node do not exists with key: " + key);
        } else {
            if (temp == head) {
                head = temp.next;
                temp = null;
            } else {
                Node prev = head;
                Node curr = head.next;
                while (curr != temp) {
                    prev = curr;
                    curr = curr.next;
                }
                prev.next = curr.next;
                temp = null;
            }
            count--;
            System.out.println("Node deleted");
        }
    }

    void update(int key, int data) {
        Node temp = isNodeExists(key);
        if (temp == null) {
            System.out.println("Node do not exists with key: " + key);
        } else {
            temp.val = data;
            System.out.println("Node value updated");
        }
    }

    int countOfNodes() {
        return count;
    }

    void display() {
        if (head == null) {
            System.out.println("List is empty!");
        } else {
            Node ptr = head;
            System.out.println("Nodes in Singly Linked List are: ");
            while (ptr != null) {
                System.out.print("(" + ptr.key + ", " + ptr.val + ") ---> ");
                ptr = ptr.next;
            }
            System.out.println();
        }
    }
}

public class Singly_Linked_List_Program_4 {

    public static void main(String[] args) {

        SinglyLinkedList s = new SinglyLinkedList();
        int key1, data1, k1, choice, ans;

        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("Enter your choice:");
            System.out.println("0 -> exit");
            System.out.println("1 -> appendNode()");
            System.out.println("2 -> prependNode()");
            System.out.println("3 -> insertNode()");
            System.out.println("4 -> deleteNode()");
            System.out.println("5 -> countOfNodes()");
            System.out.println("6 -> update()");
            System.out.println("7 -> display()");

            choice = sc.nextInt();

            // dynamic memory allocation
            Node n1 = new Node();

            switch (choice) {
                case 0:
                    System.out.println("Exiting program...!\nThank you!");
                    break;

                case 1:
                    System.out.print("Enter key and data of node you want to append: ");
                    key1 = sc.nextInt();
                    data1 = sc.nextInt();
                    n1.key = key1;
                    n1.val = data1;
                    s.appendNode(n1);
                    break;

                case 2:
                    System.out.println("Enter key and data of node you want to prepend: ");
                    key1 = sc.nextInt();
                    data1 = sc.nextInt();
                    n1.key = key1;
                    n1.val = data1;
                    s.prependNode(n1);
                    break;

                case 3:
                    System.out.println("Enter key of node after which you want to insert node: ");
                    k1 = sc.nextInt();
                    System.out.println("Enter key and data of node you want to insert: ");
                    key1 = sc.nextInt();
                    data1 = sc.nextInt();
                    n1.key = key1;
                    n1.val = data1;
                    s.insertNode(n1, k1);
                    break;

                case 4:
                    System.out.println("Enter key of node you want to delete: ");
                    key1 = sc.nextInt();
                    s.deleteNode(key1);
                    break;

                case 5:
                    ans = s.countOfNodes();
                    System.out.println("Count of nodes in Singly Linked List is: " + ans);
                    break;

                case 6:
                    System.out.println("Ente key of node you want to update: ");
                    key1 = sc.nextInt();
                    System.out.println("Ente value of node you want to update: ");
                    data1 = sc.nextInt();
                    s.update(key1, data1);
                    break;

                case 7:
                    s.display();
                    break;

                default:
                    System.out.println("Enter valid choice!");
            }
            System.out.println();
        } while (choice != 0);

        return;
    }
}
