#ifndef CXX_PRO_QUEUE_H
#define CXX_PRO_QUEUE_H

#include <iostream>
#include <queue>
using namespace std;

namespace cxxProQueue {

void print(const priority_queue<int>& pq) {
    cout << "the queue is " << (pq.empty() ? "" : "not") << " empty\n";
    cout << "the queue contains " << pq.size() << " elements\n";
    cout << "the highest priority element is " << pq.top() << endl;
}

int main() {
    priority_queue<int> pq;     // create a queue object
    pq.push(4);                 // add some elements to it
    pq.push(3);
    pq.push(5);
    pq.push(1);

    print(pq);

    // insert a new element in the queue
    cout << "\nadding element with value 2\n";
    pq.push(2);
    print(pq);

    // remove the top element
    cout << "\nremoving top element\n";
    pq.pop();
    print(pq);

    return 0;
}
}     // namespace cxxProQueue
#endif     // CXX_PRO_QUEUE_H
