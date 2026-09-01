#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
class B;

class A
{
    int superSecret;

public:
    void setSecret(B &, int);
};

class B
{
    friend class A;
    int secret;

public:
    int getSecret() { return secret; };
};

#endif // TEST_H_INCLUDED