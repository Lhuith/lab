#ifndef UNIONS_H
#define UNIONS_H

#include <iostream>
#include <variant>

using namespace std;

namespace unions {

enum class TokenType { CHAR,
                       INT,
                       DOUBLE };

union Token {
    // members are public by default
    char c;
    int i;
    double d;
};
struct TaggedToken {
    Token token;
    TokenType type;     // "Tag" field to indicate which member is in use
};

class TokenWrapper {
    Token token;
    TokenType type;

   public:
    void set_char(char c) {
        type = TokenType::CHAR;     // char member in use
        token.c = c;
    }
    double get_double() {
        if (type == TokenType::DOUBLE)
            return token.d;
        else
            throw std::invalid_argument("double member not in use");
    }
};

class Test {
    //    public:
    //     Test() {
    //         cout << "constructor called";
    //     }
    //     ~Test() {
    //         cout << "destructor called";
    //     }
};

int main() {
    // Token token;
    // token.type = TokenType::CHAR;
    // token.c = 'Z';     // char member is in use

    // cout << token.d << endl;     // double member not in use - has undefined value

    // TaggedToken tk;
    // tk.type = TokenType::DOUBLE;     // char member is in use
    // // ttoken.c = 'Z';
    // tk.token.d = 2.0;

    // // check if safe to access double member
    // if (tk.type == TokenType::DOUBLE)
    //     cout << tk.token.d << endl;
    // else
    //     cout << "double member not in use\n";

    // TokenWrapper tw;
    // tw.set_char('Z');

    // // check if safe to access double member
    // try {
    //     double d = tw.get_double();
    //     cout << d << endl;
    // } catch (std::exception& e) {
    //     cout << "caught exception: " << e.what() << endl;
    // }

    variant<char, int, double> v;
    // v = 'Z';     // char member is in use
    v = 2;

    if (holds_alternative<double>(v))
        cout << get<double>(v) << endl;
    else
        cout << "double member not in use\n";

    return 0;
}
}     // namespace unions
#endif     // UNIONS_H