#include "task1.h"

std::ostream& operator<<(std::ostream& os, const PlainFigure& figure) 
{
    figure.Print(os);
    return os;
}

PlainFigure::~PlainFigure() 
{

}

Rectangle::Rectangle(double a, double b)
    : a(a), b(b)
{

}

Rectangle::~Rectangle()
{}

double Rectangle::Perimeter()
{
    return this->a * 2 + this->b * 2;
}

double Rectangle::Area()
{
    return this->a * this->b;
}

void Rectangle::Print(std::ostream& out) const
{
    out << "Printing some data for rectangle!\n";
}

Triangle::Triangle(double a, double b, double c)
    : a(a), b(b), c(c) {} 

Triangle::~Triangle() {}

double Triangle::Perimeter()
{
    return a + b + c;
}

double Triangle::Area()
{
    return a * b * c; // :)
}

void Triangle::Print(std::ostream& os) const
{
    os << "Printing data for triangle!\n";
}