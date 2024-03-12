#include "task1.h"
#include <memory>
#include <vector>


int main()
{
    Rectangle* figure = new Rectangle(10, 20);
    std::cout << figure->Area() << std::endl;
    figure->Print(std::cout);
    std::cout << *figure << std::endl;

    std::vector<PlainFigure*> figures;
    figures.push_back(new Rectangle(10, 20));
    figures.push_back(new Triangle(5, 15, 25));

    for (const auto& e : figures)
    {
        std::cout << *e << std::endl;
    }
}