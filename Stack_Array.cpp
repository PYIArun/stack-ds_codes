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
};

int main(){

    Stack <int> s;

    s.push(4);
    s.push(9);
    s.push(234);
    s.push(21);
    s.push(34);
    cout<< "POPPED: " << s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    cout<< "POPPED: "<< s.pop();
    cout<<endl;
    // cout<< "TOP ELEMENT: "<< s.topEl()<<endl;
    s.push(9);
    s.push(234);
    s.push(21);
    s.push(34);
        s.push(9);
    s.push(234);
    s.push(21);
    s.push(34);
        s.push(9);
    s.push(234);
    s.printStack();

}