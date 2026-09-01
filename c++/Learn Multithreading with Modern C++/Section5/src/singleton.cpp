#include "singleton.hpp"

// static member function to obtain the Singleton object
// Singleton* Singleton::get_Singleton() {
//     if (single == nullptr)
//         single = new Singleton;
//     return single;
// }

// function to object the Singleton object
Singleton& get_Singleton() {
    // initialized by the first thread that executes this code
    static Singleton single;
    return single;
}