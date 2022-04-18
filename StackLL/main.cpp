#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
    Stack stack1 = Stack();

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    stack1.print();

    cout << stack1.top() << endl;

    for(int i = 0; i < 5; i++){
        cout << stack1.pop() << ' ';
    }
    cout << endl;

}
