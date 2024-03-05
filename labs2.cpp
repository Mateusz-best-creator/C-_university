#include <iostream>

class Vektor3d 
{
    double array[3]; //field with array of numbers
public:
    Vektor3d (double x1,double x2,double x3)
    { //constructor
        array[0] = x1;
        array[1] = x2;
        array[2] = x3;
    }

    const double& operator[](std::size_t i) const
    {
        return array[i];
    }
};
std::ostream& operator<<(std::ostream& ostr, const Vektor3d& v)
{
    ostr << "Vector3d{";
    for(std::size_t i = 0; i < 3; i++)
    {
        if(i > 0)
            ostr << ',';
            ostr << v[i];
    }
    ostr << ')';
    return ostr;
}

int main()
{
    Vektor3d v1{1,2,3}; //object creation
    std::cout << sizeof v1 << std::endl;
    Vektor3d v2{4,5,6}; //object creation
    Vektor3d v1Copy1{v1}; //object creation – copy constructor
    Vektor3d v1Copy2 = v1; //object creation – copy constructor
    std::cout << "v1: " << v1 << std::endl; // Print v1
    std::cout << "v2: " << v2 << std::endl; // Print v2
    v1 = v2; //assignment
    std::cout << "v1: " << v1 << std::endl; // print v1
    std::cout << "v1Copy1: " << v1Copy1 << std::endl; //Print v1Copy1
    std::cout << "v1Copy2: " << v1Copy2 << std::endl; //Print v1Copy2
    return 0;
}