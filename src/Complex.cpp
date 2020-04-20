#include "Complex.h"
#define pi 3.1415926535
Complex Pow(const Complex &c, const int deg)
{
    Complex res = 1;
    for(int i = 0; i < deg; i++)
        res*=c;
    return res;
}
Complex::Complex()
{
    //ctor
}
Complex::Complex(const double real,const double imaginary)
{
    m_real = real;
    m_imaginary = imaginary;
}
Complex::Complex(const double real)
{
    m_real = real;
    m_imaginary = 0;
}
Complex Complex::operator+(const Complex& other)const
{
    return Complex(m_real + other.m_real, m_imaginary + other.m_imaginary);
}
Complex Complex::operator-(const Complex& other)const
{
    return Complex(m_real - other.m_real, m_imaginary - other.m_imaginary);
}
Complex Complex::operator-(const double r)const
{
    return Complex(m_real - r, m_imaginary);
}
Complex Complex::operator*(const Complex& other)const
{
    double real = m_real*other.m_real - m_imaginary*other.m_imaginary;
    double im =  m_real*other.m_imaginary + m_imaginary*other.m_real;
    return Complex(real, im);
}
Complex Complex::operator*(const double r)const
{
    return Complex(m_real*r, m_imaginary*r);
}
Complex Complex::operator/(const double real)const
{
    return Complex(m_real/real, m_imaginary/real);
}
double Complex::NormInSquare()const
{
    return (m_real*m_real + m_imaginary*m_imaginary);
}
Complex Complex::operator/(const Complex& other)const
{
    return ((*this)*other.Conjugate())/other.NormInSquare();
}
Complex& Complex::operator*=(const Complex& other)
{
     double real = m_real*other.m_real - m_imaginary*other.m_imaginary;
     double im =  m_real*other.m_imaginary + m_imaginary*other.m_real;
     m_real = real;
     m_imaginary = im;
     return *this;
}
Complex Complex::Conjugate()const
{
    return Complex(m_real, -m_imaginary);
}
bool Complex::operator==(const Complex& other)
{
    if(m_real!=other.m_real)
        return false;
    if(m_imaginary!=other.m_imaginary)
        return false;
    return true;
}
double Complex::getRadius()const
{
    return sqrt(NormInSquare());
}
double Complex::getSin()const
{
    return m_imaginary/getRadius();
}
double Complex::getCos()const
{
    return m_real/getRadius();
}
double Complex::getAngle()const
{
    return acos(getCos());
}
std::vector<Complex> Complex::roots(double deg)const
{
    double r = getRadius();
    double angle = getAngle();
    std::vector<Complex> roots;
    for(int k = 0; k < deg; k++)
    {
        double real = pow(r,1/deg)*cos((angle + 2*pi*k)/deg);
        double im = pow(r,1/deg)*sin((angle + 2*pi*k)/deg);
        roots.push_back(Complex(real, im));
    }
    return roots;
}
std::ostream& operator<<(std::ostream& out, const Complex& c)
{
    out<<c.m_real<<' ';
    if(c.m_imaginary>=0)
        out<<"+ ";
    out<<c.m_imaginary<<'i';
    return out;
}
double& operator=(const Complex& c)
{
    static_assert(c.m_imaginary==0, "right value is complex");
    return m_real;
}
Complex::~Complex()
{

}
