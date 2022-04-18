#include <iostream>
#include "QueueType.h"
using namespace std;

int main() {
    Queue<int> que;

    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    que.Enqueue(4);

    que.print();

    que.Dequeue();
    que.Dequeue();
    que.Dequeue();

    que.print();
}
