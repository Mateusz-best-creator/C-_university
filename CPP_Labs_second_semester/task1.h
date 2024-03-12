#include <iostream>

class PlainFigure 
{
protected:
    virtual void Print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const PlainFigure& figure);
public:
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
    virtual ~PlainFigure();
};

class Rectangle : public PlainFigure
{
private:
    double a,b;

public:
    Rectangle(double a, double b);
    ~Rectangle() override;


    double GetA() const { return a; }
    double& SetA() { return a; }
    double GetB() const { return b; }
    double& SetB() { return b; }

    double Perimeter() override;
    double Area() override;
    void Print(std::ostream& out) const override;
};

class Triangle : public PlainFigure
{
private:
    double a, b, c;

public:
    Triangle(double, double, double);
    ~Triangle();

    // Getters and settters
    // ...

    double Perimeter() override;
    double Area();
    void Print(std::ostream& out) const override;
};