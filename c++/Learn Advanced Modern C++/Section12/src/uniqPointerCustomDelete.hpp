#ifndef UNIQ_POINTER_CUSTOM_DELETE_H
#define UNIQ_POINTER_CUSTOM_DELETE_H

#include <iostream>
#include <memory>

using namespace std;

namespace uniqPointerCustomDelete {

/// Code from C networking API ///
struct destination { /* ... */
};
struct connection { /* ... */
};

// function to open a connection
connection connect(destination dest) {
    std::cout << "connecting\n";
    connection conn;
    return conn;
}

// function to close a connection
void disconnect(connection conn) {
    std::cout << "disconnecting\n";
}

/// end of code from c networking API ///

// custom deleter to close network connection
auto end_connection = [](connection* conn) { disconnect(*conn); };

void get_data(const destination& dest) {
    connection conn = connect(dest);
    std::unique_ptr<connection, decltype(end_connection)> ptr(&conn, end_connection);     // unique_ptr takes ownership
    throw std::out_of_range("yikes");
    std::cout << "getting data ... \n";
    // // delete conn???
}

int main() {
    destination dest;
    try {
        get_data(dest);
    } catch (...) {
        cout << "caught!\n";
    }

    cout << "testy test" << endl;
    return 0;
}
}     // namespace uniqPointerCustomDelete
#endif     // UNIQ_POINTER_CUSTOM_DELETE_H