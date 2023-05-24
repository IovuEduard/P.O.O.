#include <iostream>
#include "Polynom.h"
using namespace std;

int main()
{
    int d = 5;
    float* coef = new float[d];
    for (int i = 0; i < d; i++)
        coef[i] = 2 * i;
    int d2 = 3;
    float* coef2 = new float[d];
    for (int i = 0; i < d; i++)
        coef2[i] = i + 2;
    Polynom<float> p1(d, coef);
    Polynom<float> p2(d2, coef2);
    Polynom<float> p3 = p2;
    Polynom<float> p4 = p2 - p1;
    cout<<p1<<"\n"<<p2<<"\n"<<p3<<"\n";
    p3=p1;
    cout<<p1<<"\n"<<p2<<"\n"<<p3<<"\n";
    cout << p2 << "\n" << p1 << "\n";
    cout << p4 << "\n" << p1;
    p2.coeff[0]++;


    return 0;
}