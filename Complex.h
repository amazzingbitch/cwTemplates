//
// Created by Eldo on 20.12.2021.
//

#ifndef COURSE__WORK_COMPLEX_H
#define COURSE__WORK_COMPLEX_H


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

class Complex {
public:
    Complex();
    Complex(double real);
    Complex(double real, double im);
    Complex(const Complex& other);
    double GetReal();
    char* GetStr();
    double GetIm();
    void SetIm(double im);
    void SetReal(double real);
    ~Complex();
    static Complex Sum(Complex &val1, Complex &val2);
    Complex Dif(Complex &other);
    Complex Mult(Complex &other);
    Complex Div(Complex &other);
private:
    double real;
    double im;
    char* str = nullptr;
    int N;
    void toString();
};


#endif //COURSE__WORK_COMPLEX_H
