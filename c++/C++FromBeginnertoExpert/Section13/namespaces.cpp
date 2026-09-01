#include <iostream>

// namespaces
namespace mySpace
{
    class MyNewLine
    {
        std::string text;

    public:
        MyNewLine(std::string t = "\n\n\n") { this->text = t; }
        std::string toString()
        {
            return text;
        };
    };
    std::ostream &operator<<(std::ostream &out, MyNewLine &o)
    {
        return out << o.toString();
    }

    MyNewLine endl;
}

using namespace mySpace;

int main()
{
    int a = 50;
    std::cout << "this is text" << endl;

    return 0;
}