#include <iostream>

using namespace std;

class Foo{
    int x, y;

    public:
        Foo(int x);
        Foo();
        int getX(){return x;}
};

Foo::Foo(int x){
    this -> x = x;
}

int main(void){
    
    Foo *foo = new Foo(10);

    cout<<"The Value of foo's x is "<< foo->getX() <<endl;
}
