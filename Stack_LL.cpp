#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Stack{

    Node<T> *head;
    Node<T> *tail;

    public:

    Stack(){
        head = nullptr;
        tail = nullptr;
    }

    void push(T x){
        
        Node<T> *newNode = new Node<T>(x);
        if(isEmpty()){

            // cout<<"hello";
            head = newNode;
            tail = head;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
    }

    T pop(){
        
        if(isEmpty()){
            cout<< "Stack is empty!";
            return T() ;
        }
        Node<T> *temp = head;
        Node<T> *prev = nullptr;

        if( head==tail){
            T element = head->data;
            Node<T> *toDelete = head;
            head = nullptr;
            tail = nullptr;
            delete toDelete;
            return element;
        }

        while(temp->next!=tail){
            temp = temp->next; 
        }

        T element = tail->data;
        delete tail;
        
        tail = temp;
        tail->next = nullptr;
        return element;
    }

    T topEl(){
        if(isEmpty()){
            cout<<"Stack is Empty!";
            return T();
        }

        return tail->data;
    }

    bool isEmpty(){
        if(head==nullptr && tail == nullptr){
            return true;
        }

        return false;
    }

    void printStack(){

        if(isEmpty()){
            cout<<"Stack is Empty!";
            return;
        }

        Node<T> *temp = head;

        while(temp!=nullptr){

            cout<< temp->data << " | ";
            temp = temp->next;

        }
        cout<<endl;

    }


};



int main(){
    Stack <int> s;
    s.push(51);
    s.push(51);
    s.push(51);
    s.pop();
    s.pop();
    s.push(12);
    s.push(12);
    s.push(12);
    s.push(12);
    s.printStack();

}