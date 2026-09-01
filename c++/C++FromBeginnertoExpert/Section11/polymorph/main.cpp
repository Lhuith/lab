#include <iostream>
#include "farm.hpp"

using namespace std;

void voiceOfAnimal(Animal *);
void voiceOfAnimal(Animal &);
int main()
{
    // Animal animal;
    // Dog dog;
    // Cat cat;
    // Cow cow;

    // // cout << animal.getVoice() << endl;
    // // cout << dog.getVoice() << endl;
    // // cout << cat.getVoice() << endl;
    // // cout << cow.getVoice() << endl;

    // voiceOfAnimal(cat);

    // // Animal *p = &dog;
    // // cout << p->getVoice() << endl;
    Animal *dog = new Dog;

    delete dog;
    return 0;
}

void voiceOfAnimal(Animal &a)
{
    cout << a.getVoice() << endl;
}