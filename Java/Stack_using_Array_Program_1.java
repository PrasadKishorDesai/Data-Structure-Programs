package Java;

import java.util.Scanner;

class Stack {

    int[] arr;
    int arrSize;
    int top;

    Stack() {
        System.out.println("Enter size of stack: ");
        Scanner sc = new Scanner(System.in);
        this.arrSize = sc.nextInt();
        this.arr = new int[this.arrSize];
        top = -1;
    }

    boolean isFull() {
        return top == (arrSize - 1);
    }

    boolean isEmpty() {
        return top == -1;
    }

    void push(int element) {
        if (isFull()) {
            System.out.println("Stack is already full, cannot add element!");
        } else {
            ++top;
            arr[top] = element;
            System.out.println("Element pushed on stack");
        }
    }

    void pop() {
        if (isEmpty()) {
            System.out.println("Stack is already empty, cannot remove element!");
        } else {
            int elem = arr[top];
            arr[top] = 0;
            top--;
            System.out.println("Element popped\nValue of popped element is: " + elem);
        }
    }

    int peek() {
        if (isEmpty()) {
            return 0;
        }
        return arr[top];
    }

    void clear() {
        arr = null;
    }

    int count() {
        return top + 1;
    }

    void display() {
        System.out.println("Elements of stack are: \n");
        for (int i = arrSize - 1; i >= 0; i--) {
            System.out.println("|     " + arr[i] + "     |");
            System.out.println("-------------");
        }
    }
}

public class Stack_using_Array_Program_1 {

    public static void main(String[] args) {
        Stack s = new Stack();
        int choice, element, ans;

        do {
            System.out.println("Enter your choice:");
            System.out.println("0 -> exit");
            System.out.println("1 -> push()");
            System.out.println("2 -> pop()");
            System.out.println("3 -> isFull()");
            System.out.println("4 -> isEmpty()");
            System.out.println("5 -> peek()");
            System.out.println("6 -> count()");
            System.out.println("7 -> display()");

            Scanner sc = new Scanner(System.in);
            choice = sc.nextInt();

            switch (choice) {
                case 0:
                    s.clear();
                    System.out.println("Exiting program...!\nThank you!");
                    break;

                case 1:
                    System.out.println("Enter element you want to push: ");
                    element = sc.nextInt();
                    s.push(element);
                    break;

                case 2:
                    s.pop();
                    break;

                case 3:
                    if (s.isFull()) {
                        System.out.println("Stack is Full");
                    } else {
                        System.out.println("Stack is not Full");
                    }
                    break;

                case 4:
                    if (s.isEmpty()) {
                        System.out.println("Stack is Empty");
                    } else {
                        System.out.println("Stack is not Empty");
                    }
                    break;

                case 5:
                    ans = s.peek();
                    System.out.println("Element at top of Stack is: " + ans);
                    break;

                case 6:
                    ans = s.count();
                    System.out.println("Count of elements in stack is: " + ans);
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
