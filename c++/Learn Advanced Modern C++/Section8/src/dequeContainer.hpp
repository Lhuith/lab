#ifndef DEQUE_CONTAINER_H
#define DEQUE_CONTAINER_H

#include <deque>
#include <iostream>

using namespace std;

namespace dequeContainer {
int main() {
    deque<int> dq{4, 2, 3, 5, 1};

    dq.push_back(4);
    dq.push_back(2);
    dq.push_front(1);
    dq.push_front(5);
    dq.push_front(3);

    for (auto it : dq)
        cout << it << ", ";
    cout << endl;

    return 0;
}
}     // namespace dequeContainer
#endif     // DEQUE_CONTAINER_H