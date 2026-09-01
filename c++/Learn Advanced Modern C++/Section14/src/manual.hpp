#ifndef MANUAL_H
#define MANUAL_H

#include <iostream>
#include <string>

// template declaration only
template <typename T>
std::ostream& print(std::ostream& os, const T& t);

// declare non-template function
void func(const std::string& str);

#endif     // MANUAL_H