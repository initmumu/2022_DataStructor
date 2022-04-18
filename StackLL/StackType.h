#include <iostream>
using namespace std;

typedef int type;

class EmptyStack{};
class FullStack{};

struct Node{
    type info;
    Node* next;
};

class Stack{
private:
    Node* topPtr;
public:
    Stack(){
        topPtr = NULL;
    }

    bool isFull(){
        Node* location;

        try{
            location = new Node;
            delete location;
            return false;
        }
        catch (bad_alloc){
            return true;
        }
    }

    bool isEmpty(){
        if (topPtr == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void push(type item){
        if(isFull())
            throw FullStack();

        if (topPtr == NULL){
            topPtr = new Node();
            topPtr -> info = item;
        }
        else{
            Node* newItem = new Node();
            newItem -> info = item;
            newItem -> next = topPtr;
            topPtr = newItem;
        }
    }

    type top(){
        if (isEmpty())
            throw EmptyStack();

        return topPtr -> info;
    }

    type pop(){
        if(isEmpty())
            throw EmptyStack();

        type value = topPtr -> info;
        Node* tmp = topPtr;

        delete topPtr;
        topPtr = tmp -> next;
        return value;

    }

    void print(){
        if (isEmpty()){
            throw EmptyStack();
        }

        Node* location = topPtr;
        while(location != NULL) {
            cout << location -> info << ' ';
            location = location -> next;
        }
        cout << endl;
    }

    ~Stack(){
        Node* location;

        while(location == NULL){
            location = topPtr;
            topPtr = topPtr -> next;
            delete location;
        }
    }
};


