#include <iostream>
using namespace std;

#define SIZE 10

template <class T>
class Stack{

    private:
    int top;

    public:
    T arr[SIZE];
    Stack(){
        top = -1;
    }

    void push(T x){

        if(isFull()){
            cout<<"Stack Overflow! ";
            return;
        }

        top++;
        arr[top] = x;

    }

    T pop(){
        
        if(isEmpty()){
            cout<<"Stack Underflow! ";
            return 0;
        }
        int index = top;
        top--;
        return arr[index];

    }

    T topEl(){
        return arr[top];
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }

        return false;
    }

    bool isFull(){

        if(top==SIZE-1){
            return true;
        }

        return false;

    }

    void printStack(){
        
                
        if(isEmpty()){
            cout<<"Stack is Empty! ";
            return;
        }
        for(int i =0 ; i<top+1; i++){
            cout<< arr[i]<< " | ";
        }

    }

    int size(){
        return top+1;
    }
};

int main(){

    Stack<int> s;
    int option;

    do {
        cout << "\nMenu Driven Program:\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Check Stack Contents\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> option;

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
                int element2 = s.pop();
                if (!s.isEmpty()) {
                    cout << "Element " << element2 << " successfully popped from the stack.\n";
                }
                break;
            }
            case 3:
                s.printStack();
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty!" : "Stack is not empty!") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full!" : "Stack is not full!") << endl;
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