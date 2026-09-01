#include <iostream>
#define print(a) cout << a << endl;

using namespace std;

main() {
    double v1, v2;

    beginning:
    system("cls");

    print("enter first number: ")
    cin >> v1;

    print("enter second number: ")
    cin >> v2;

    print("what ya wanna do?")
    print("+ add")
    print("- sub")
    print("* mul")
    print("/ div")
    print("")

    char decision;
    cin >> decision;

    system("cls");
    switch(decision){
        case '+':
            cout << v1 << " + " << v2 << " = " << (v1 + v2) << endl;
            break;
        case '-':
            cout << v1 << " - " << v2 << " = " << (v1 - v2) << endl;
            break;
        case '*':
            cout << v1 << " * " << v2 << " = " << (v1 * v2) << endl;
            break;
        case '/':
            if(v2) { // if anything but zero, nice trick
                cout << v1 << " / " << v2 << " = " << (v1 / v2) << endl;
            } else {
                cout << "can't do that" << endl;
            }
            break;
        default:
            cout << "wrong character typed";
    }
    char decision2;
    cout << "continue? (y/Y) ... or anything to quit" << endl;
    cin >> decision2;

    if(decision2 == 'y' || decision2 == 'Y')
        goto beginning;
}
