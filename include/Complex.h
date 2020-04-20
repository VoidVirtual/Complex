#pragma once
#include <iostream>
#include <cmath>
#include <vector>
class Complex
{
public:
    Complex();
    Complex(const double r, const double i);
    Complex(const double r);
    Complex operator+(const Complex& other)const;
    Complex operator+(const double r)const;
    Complex operator-(const Complex& other)const;
    Complex operator-(const double r)const;
    Complex operator*(const Complex& other)const;
    Complex operator*(const double r)const;
    Complex operator/(const double real)const;
    Complex operator/(const Complex& other)const;
    Complex& operator=(const double r)const;
    Complex& operator*=(const Complex& c);
    Complex Conjugate()const;
    double Norm()const;
    double getRadius()const;
    double getSin()const;
    double getCos()const;
    double getAngle()const;
    std::vector<Complex> roots(double deg)const;
    bool operator==(const Complex& other);
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend double& operator=(const Complex& c);
    virtual ~Complex();
private:
    double NormInSquare()const;
    double m_real;
    double m_imaginary;
};
Complex Pow(const Complex& c, const int deg);
