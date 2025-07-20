package Java;

import java.util.Scanner;

class CircularQueue {

    int[] arr;
    int arrSize, front, rear;

    CircularQueue() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of queue: ");
        arrSize = sc.nextInt();
        arr = new int[arrSize];
        front = -1;
        rear = -1;
    }

    boolean isFull() {
        return (rear + 1) % arrSize == front;
    }

    boolean isEmpty() {
        return front == -1 && rear == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            System.out.println("Queue is already full, cannot add element to it");
            return;
        } else if (isEmpty()) {
            front = 0;
            rear = 0;
            arr[rear] = element;
        } else {
            rear = (rear + 1) % arrSize;
            arr[rear] = element;
        }
        System.out.println("Element enqueued");
    }

    void dequeue() {
        int elem = 0;
        if (isEmpty()) {
            System.out.println("Queue is already empty, cannot remove element from it");
        } else if (front == rear) {
            elem = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
        } else {
            elem = arr[front];
            arr[front] = 0;
            front = (front + 1) % arrSize;
        }
        System.out.println("Element removed from the queue is: " + elem);
    }

    int countOfElements() {
        return !isEmpty() ? ((rear - front + arrSize) % arrSize) + 1 : 0;
    }

    void display() {
        System.out.println("Elements in Queue are: ");
        for (int i = 0; i < arrSize; i++) {
            System.out.print("|     " + arr[i] + "     ");
        }
        System.out.println("|");
    }

    void clear() {
        arr = null;
        front = -1;
        rear = -1;
    }
}

public class Circular_Queue_using_Array_Program_3 {

    public static void main(String[] args) {
        CircularQueue q = new CircularQueue();
        int choice, element, ans;

        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("Enter your choice:");
            System.out.println("0 -> exit");
            System.out.println("1 -> enqueue()");
            System.out.println("2 -> dequeue()");
            System.out.println("3 -> isFull()");
            System.out.println("4 -> isEmpty()");
            System.out.println("5 -> countOfElements()");
            System.out.println("6 -> display()");

            choice = sc.nextInt();

            switch (choice) {
                case 0:
                    q.clear();
                    System.out.println("Exiting program...!\nThank you!");
                    break;

                case 1:
                    System.out.print("Enter element you want to enqueue: ");
                    element = sc.nextInt();
                    q.enqueue(element);
                    break;

                case 2:
                    q.dequeue();
                    break;

                case 3:
                    if (q.isFull()) {
                        System.out.println("Queue is Full");
                    } else {
                        System.out.println("Queue is not Full");
                    }
                    break;

                case 4:
                    if (q.isEmpty()) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Queue is not Empty");
                    }
                    break;

                case 5:
                    ans = q.countOfElements();
                    System.out.println("Count of elements in Queue is: " + ans);
                    break;

                case 6:
                    q.display();
                    break;

                default:
                    System.out.println("Enter valid choice!");
            }

            System.out.println();

        } while (choice != 0);

        sc.close();
        return;
    }
}
