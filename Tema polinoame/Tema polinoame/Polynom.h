#include<iostream>
using namespace std;
template <typename T>
class Polynom
{
public:
    int degree;
    T* coeff;
    Polynom(int d, T f[]);
    Polynom(const Polynom& p);
    Polynom& operator =(const Polynom p2);
    friend ostream& operator <<(ostream& output, Polynom& p);
    Polynom operator -(Polynom p2);
    Polynom operator +(Polynom p2);
    float calc(float x);
    Polynom operator *(Polynom p2);

};