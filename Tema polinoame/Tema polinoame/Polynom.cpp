#include<iostream>
using namespace std;
#include"Polynom.h"

template <typename T>
float Polynom<T>::calc(float x) 
{
    int degree;

    float sum = 0;
    for (int i = 0; i < degree; i++)
    {
        float putere = 1;
        int j = i;
        while (j)
        {
            putere *= x;
            j--;
        }
        sum += coeff[i] * putere;
    }
    return sum;
}


template <typename T>
Polynom<T> ::Polynom(int d, T f[])
{
    degree = d;
    coeff = new T[d];
    for (int i = 0; i < degree; i++)
        coeff[i] = f[i];
}

template <typename T>
Polynom<T>::Polynom(const Polynom& p)
{
    degree = p.degree;
    coeff = new T[p.degree];
    for (int i = 0; i < p.degree; i++)
        coeff[i] = p.coeff[i];

}

template <typename T>
Polynom<T>& Polynom<T>:: operator =(const Polynom p2)
{
    coeff = new T * [p2.degree];
    degree = p2.degree;
    for (int i = 0; i < degree; i++)
        coeff[i] = p2.coeff[i];
    return this;
}

template <typename T>
ostream& operator <<(ostream& output, Polynom<T>& p)
{
    output << p.degree << "\n";
    for (int i = 0; i < p.degree; i++)
        output << p.coeff[i] << " ";
    return output;
}

template <typename T>
Polynom<T> Polynom<T>::operator -(Polynom p2)
{


    if (p2.degree > degree)
    {
        Polynom p4 = p2;
        for (int i = 0; i < degree; i++)
        {
            p4.coeff[i] = coeff[i] - p2.coeff[i];
        }
        for (int i = degree; i < p2.degree; i++)
            p4.coeff[i] *= -1;
        Polynom p3(p4.degree, p4.coeff);

        return p3;
    }
    else
    {
        T* f = new T[degree];
        f = coeff;
        for (int i = 0; i < p2.degree; i++)
        {
            f[i] = coeff[i] - p2.coeff[i];
        }
        Polynom p3(degree, f);

        return p3;
    }
    return p2;
}


template <typename T>
Polynom<T> Polynom<T>:: operator +(Polynom p2)
{
    Polynom p4(p2);
    if (p2.degree > degree)
    {
        for (int i = 0; i < degree; i++)
        {
            p4.coeff[i] = coeff[i] + p2.coeff[i];
        }
        Polynom p3(p4.degree, p4.coeff);

        return p3;
    }
    else
    {
        T* f = new T[degree];
        f = coeff;
        for (int i = 0; i < p2.degree; i++)
        {
            f[i] = coeff[i] + p2.coeff[i];
        }
        Polynom p3(degree, f);

        return p3;
    }
    return p2;
}

template <typename T>
Polynom<T> Polynom<T>:: operator *(Polynom p2)
{
    T* f = new T[p2.degree + degree - 1]();
    for (int i = 0; i < degree; i++)
        for (int j = 0; j < p2.degree; j++)
        {
            f[i + j] += coeff[i] * p2.coeff[j];
        }
    Polynom p3(p2.degree + degree - 1, f);
    return p3;
}