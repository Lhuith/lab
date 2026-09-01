#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

class PersonalData
{
private:
    short age;
    int *p;

public:
    PersonalData();
    PersonalData(short);
    ~PersonalData();
    /*
        setting age, where age < 0, will be set to 10
    */
    void setAge(int);
    short getAge() { return age; };
};

#endif // PEOPLE_H_INCLUDED