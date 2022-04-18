#include <iostream>
using namespace std;

class EmptyQueue{};
class FullQueue{};

template <typename type>
struct Node{
    type info;
    Node* next;
};

template <typename type>
class Queue{
private:
    Node<type>* front;
    Node<type>* rear;

public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() const{
        return (front == NULL);
    }

    bool isFull() const{
        try{
            Node<type>* tmp = new Node<type>;
            delete tmp;
            return false;
        }
        catch(bad_alloc){
            return true;
        }
    }

    void makeEmpty(){
        Node<type>* tmp;

        while(front != NULL){
            tmp = front;
            front = front -> next;
            delete tmp;
        }

        rear == NULL;
    }

    void print(){
        Node<type>* location = front;

        bool moreToSearch = true;

        while (location != rear -> next){
            cout << location -> info << ' ';
            location = location -> next;
        }
        cout << endl;
    }

    void Enqueue(type item){
        Node<type>* newItem;

        newItem = new Node<type>;
        newItem -> info = item;
        newItem -> next = NULL;

        if(isEmpty()) {
            front = newItem;
        }

        else {
            rear -> next = newItem;
        }

        rear = newItem;
    }

    type Dequeue(){

        if(isEmpty())
            throw EmptyQueue();

        Node<type>* tmp = new Node<type>;
        tmp = front;
        type item = front -> info;
        front = front -> next;
        delete tmp;

        return item;

    }




};