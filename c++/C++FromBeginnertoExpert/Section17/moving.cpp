#include <iostream>
#include <memory>

using namespace std;
// ownership - who owns the pointer, who is master

class Figure
{
public:
    string name;
    Figure(string n) : name(n)
    {
        cout << "Figure " << name << ", CREATED" << endl;
    }
    ~Figure() { cout << "Figure DESTROYED" << endl; }
};

class Canvas
{
public:
    Canvas() { cout << "Canvas CREATED" << endl; }
    ~Canvas() { cout << "Canvas DESTROYED" << endl; }
    void draw(unique_ptr<Figure> &f) { cout << "Drawing on canvas: " << f->name << endl; }
    // note: unique_ptr in function method will be created then destroyed after use
};

int main()
{
    unique_ptr<Canvas> canvas = make_unique<Canvas>();
    unique_ptr<Figure> figure = make_unique<Figure>("square");

    canvas->draw(figure);
    cout << figure->name << endl;
    return 0;
}