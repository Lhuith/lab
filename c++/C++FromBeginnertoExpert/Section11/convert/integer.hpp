#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

class Integer
{
    int nr;

public:
    Integer(){};
    Integer(int); // convert constructor int x = this->nr = nr;
    ~Integer();

    operator int();
    int operator+=(Integer);
    int getNr() { return nr; }
};

#endif // INTEGER_H_INCLUDED