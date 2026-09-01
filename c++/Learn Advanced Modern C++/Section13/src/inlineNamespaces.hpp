#ifndef INLINE_NAMESPACES_H
#define INLINE_NAMESPACES_H

#include <iostream>
using namespace std;

namespace inlineNamespaces {

namespace product {
namespace version1 {
class refrigerator {
    int temperature{2};
    bool door_open{false};
    bool power_on{true};

   public:
    refrigerator() {}
    refrigerator(int temperature) : temperature(temperature) {}
    void print() {
        std::cout << "Temperature = " << temperature;
        std::cout << std::boolalpha;
        std::cout << ", door_open = " << door_open;
        std::cout << ", power_on = " << power_on;
        std::cout << std::noboolalpha;
    }
};
}     // namespace version1

inline namespace version2 {
class Internet {
   public:
    void connect() { std::cout << "connected to the internet" << std::endl; }
    void login(const std::string& id, const std::string& pw) { std::cout << "logging in!" << std::endl; }
};

class refrigerator {
    // data members
    int temperature{2};
    bool door_open{false};
    bool power_on{true};
    Internet internet;

   public:
    refrigerator() : refrigerator(2, "me", "secret") {}
    refrigerator(int temperature) : refrigerator(temperature, "me", "secret") {}
    refrigerator(const std::string& id, const std::string& pw) : refrigerator(2, id, pw) {}
    refrigerator(int temperature, const std::string& id, const std::string& pw) : temperature(temperature) {
        internet.connect();
        internet.login(id, pw);
    }
    void print() {
        std::cout << "Temperature = " << temperature;
        std::cout << std::boolalpha;
        std::cout << ", door_open = " << door_open;
        std::cout << ", power_on = " << power_on;
        std::cout << std::noboolalpha;
    }
};
}     // namespace version2

void test() {
    refrigerator fridge;
    fridge.print();
    std::cout << std::endl;
}

}     // namespace product

namespace A {
// namespace B {     // Namespace B is "nested" inside namespace A
inline namespace B {     // Namespace B is "inline" to namespace A
int x;                   // x is a symbol defined in namespace B
}
// B::x;		// to use x in namespace A, we must put B:: in front of it
// x;	// no need to put B:: here
}     // namespace A

int main() {
    // A::B::x = 5;     // to use x in the global namespace, we put A::B::
    // A::x = 5;     // to use x outside the namespaces, we can just put A::

    product::test();
    return 0;
}
}     // namespace inlineNamespaces
#endif     // INLINE_NAMESPACES_H