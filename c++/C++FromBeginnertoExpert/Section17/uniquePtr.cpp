#include <iostream>
#include <memory>

using namespace std;

class Box
{
public:
    Box() { cout << "Box created\n"; };
    ~Box() { cout << "Box destroyed\n"; };
    void display() const { cout << "displaying box.\n"; };
};

unique_ptr<Box> createBox()
{
    unique_ptr<Box> myBox = make_unique<Box>(); // create box

    // Do some ops
    myBox->display();

    // return unique_ptr<Box>; this uses move semantics
    return myBox;
}

int main()
{
    // Box *myBox = new Box(); // dynamically allocate a box;
    unique_ptr<Box> x = make_unique<Box>();

    x->display(); // use the box

    // unique_ptr<Box> myNewBox = createBox();

    /*
        code
    */

    // delete myBox; // you HAVE too delete, as in free the memory for other programs to use!
    // failure to do so will result in a memory leak.

    // if using smart pointer, no need to delete the box, it will auto delete when out of scope
    return 0;
}