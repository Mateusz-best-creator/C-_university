#include <initializer_list>
#include <iostream>

class Vector 
{
private:
    double* array;
    std::size_t size;
    
public:

    Vector(std::initializer_list<double> initList)
    : size{initList.size()}, array{new double[initList.size()]}
    {
        std::size_t i = 0;
        for(double v : initList)
        {
            array[i] = v;
            i++;
        }
    }
    
    std::size_t GetSize() const 
    {
        return size;
    }

    const double& operator[](std::size_t i) const 
    {
        return array[i];
    }

    double& operator[](std::size_t i)
    {
        return array[i];
    }

    ~Vector()
    {
        if(array != nullptr)
        delete[] array;
    }

    Vector(const Vector& other)
    {
        std::cout << "Copy constructor!\n";
        array = new double[other.GetSize()];
        for (int i = 0; i < other.GetSize(); i++)
        {
            array[i] = other[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        if (this == &other)
            return *this;
        std::cout << "Assignment operator!\n";
        delete[] array;
        array = new double[other.size];
        size = other.size;
        for (int i = 0; i < size; i++)
        {
            array[i] = other[i];
        }
        return *this;
    }

    Vector& operator=(Vector&& temp)
    {
        if (this == &temp)
            return *this;
        this->size = temp.size;
        this->array = temp.array;
        temp.size = 0;
        temp.array = nullptr;
        return *this;
    }

    Vector(Vector&& temp)
        : array(temp.array), size(temp.size)
    {
        std::cout << "Constructor for r values!\n";
        temp.array = nullptr;
        temp.size = 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
};

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    os << "Vector{";
    for(std::size_t i = 0; i < vector.GetSize(); i++)
    {
        if(i > 0)
            os << ',';
        os << vector[i];
    }
    os << '}';
    return os;
}

int main(int argc, char** argv) 
{
    Vector v1 = {1,2,3,4,5,5.5};
    std::cout << "v1: " << v1 << std::endl;
    Vector v2 = {5.5,4,3,2,1};
    std::cout << "v2: " << v2 << std::endl;
    Vector v3(Vector{10,20,30,40});
    Vector v4 = std::move(v1);

    v1 = v2; 
    
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    v4 = std::move(v3);
    std::cout << "v4 after assignment operator with r-value: " << v4 << std::endl;
    
    v1[0] = 100.0;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
}
