#include <iostream>
#include <cmath>
#include <string>

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void){

    int x = 102;
    int *pX = &x; //providing the pointer, x's address

    int y = 5;
    int *pY = &y;

    char z = 52;

    //defrencing the pointer and accessing the value/data at the address
    std::cout<<"This is x's value from pointer "<< *pX << std::endl;
    std::cout<<"This is y's value from pointer " << *pY << std::endl;

    std::cout<<"This is z's value " << z << std::endl;


    std::cout<<"Address of x is " << &x << std::endl;
    std::cout<<"Address of y is " << &x << std::endl;

    swap(x, y);
    std::cout<<"x is now " << x << " y is now " << y << std::endl;

    std::cout<<"This is x's value from pointer "<< *pX << std::endl;
    std::cout<<"This is y's value from pointer " << *pY << std::endl;

    char a[100];
    std::cout << "Please Type in Something Funny " << std::endl;
    std::cin.getline(a, 256);
    std::cout<<"Yes! "<< "\"" << a << "\"" <<" is a hilarious!"<< std::endl;

}