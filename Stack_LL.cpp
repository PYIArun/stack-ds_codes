#include <iostream>
using namespace std;

// Node class definition
template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Stack class definition
template <class T>
class Stack {
    Node<T>* head; // Points to the top of the stack

public:
    Stack() : head(nullptr) {}

    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = head; // Link new node to current head
        head = newNode;       // Update head to new node
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T(); // Return default value
        }
        Node<T>* temp = head; // The current head is the top of the stack
        T element = head->data; // Get the data from the head
        head = head->next; // Move head to the next node
        delete temp; // Free the old head node
        return element; // Return the popped element
    }

    T topEl() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T(); // Return default value
        }
        return head->data; // Return the data at head
    }

    bool isEmpty() {
        return head == nullptr; // Check if head is null
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node<T>* temp = head; // Start from the head
        while (temp != nullptr) {
            cout << temp->data << " | ";
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s; // Create a stack of integers
    int option; // Variable to hold user choice

    do {
        cout << "\nMenu Driven Program:\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Check Top Element\n";
        cout << "4. Check Empty\n";
        cout << "5. Print Stack Contents\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> option; // Get user choice

        switch (option) {
            case 1: {
                int element;
                cout << "Enter an element to push: ";
                cin >> element;
                s.push(element);
                cout << "Element " << element << " successfully pushed into the stack.\n";
                break;
            }
            case 2: {
                int element = s.pop();
                if (element) { // Check if pop was successful
                    cout << "Element " << element << " successfully popped from the stack.\n";
                }
                break;
            }
            case 3:
                if (!s.isEmpty()) {
                    cout << "Top element: " << s.topEl() << endl;
                }
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty!" : "Stack is not empty!") << endl;
                break;
            case 5:
                s.printStack();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid Input. Please enter a valid option!\n";
                break;
        }
    } while (option != 6);

    return 0;
}
