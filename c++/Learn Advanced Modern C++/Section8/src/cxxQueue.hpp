#ifndef CXX_QUEUE_H
#define CXX_QUEUE_H

#include <iostream>
#include <queue>

using namespace std;

namespace cxxQueue {

void print(const queue<int>& q) {
    cout << "the queue is " << (q.empty() ? "" : "not") << " empty\n";
    cout << "the queue contains " << q.size() << " elements\n";
    cout << "the first element is " << q.front() << endl;
    cout << "the last element is " << q.back() << endl;
}

int main() {
    queue<int> q;     // create a queue object
    q.push(4);        // add some elements to it
    q.push(3);
    q.push(5);
    q.push(1);

    print(q);

    // insert a new element at the end of the queue
    cout << "\nadding element with value 2\n";
    q.push(2);
    print(q);

    // removing the first element
    cout << "\nremoving first element\n";
    q.pop();
    print(q);

    return 0;
}
}     // namespace cxxQueue
#endif     // CXX_QUEUE_H