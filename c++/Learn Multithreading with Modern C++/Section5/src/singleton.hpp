#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton {
    // pointer to unique instance
    static Singleton *single;

    // the constructor is private

   public:
    // the copy and move operators are deleted
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;

    Singleton() { std::cout << "initializing singleton" << std::endl; }

    // static member function to obtain the Singleton object
    // static Singleton *get_Singleton();
};

// function to obtain the Singleton object
Singleton &get_Singleton();

#endif     // SINGLETON_H