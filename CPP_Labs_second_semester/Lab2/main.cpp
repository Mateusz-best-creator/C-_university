#include "library.h"
#include <iostream>

int main()
{
    // Task 1
    /*
    std::string a="Brian Ward", t="How linux works?";
    Book e;
    std::cout << "e: "<< e << std::endl;
    Book b1 = {a, t};
    std::cout << "b1: "<< b1 << std::endl;
    Book b2 = {"Aurelien Geron","Machine Learning"};
    std::cout << "b2: "<< b2 << std::endl;
    Book b3 = b1;
    std::cout << "b3: "<< b3 << "b1: " << b1 << std::endl;
    e = std::move(b2);
    std::cout << "e: "<< e << "b2:" << b2 << std::endl;
    e.set_author("Stephen Prata");
    std::cout << "e: "<< e << std::endl;
    e.set_title("C++ Language");
    std::cout << "e: "<< e << std::endl;
    */

    // Task 2
    /*
    Library e;

    std::cout << "e: "<< e << std::endl;
    Library l1 = 
    {
        {"Brian Kernighan, Dennis Ritchie", "The C Programming Language"},
        {"Jonathan W. Valvano", "Embedded Systems: Real-Time Operating Systems for Arm Cortex-M Microcontrollers"},
        {"Robert Love", "Linux Kernel Development"}
    };
    std::cout << "l1: "<< l1 << std::endl;
    Library l2;
    std::cout << "l2: "<< l2 << std::endl;
    l2.push_back({"Robert C. Martin", "Clean Code"});
    l2.push_back({"Jonathan Corbet, Alessandro Rubini, Greg Kroah-Hartman", "Linux Device Drivers"});
    std::cout << "l2: "<< l2 << std::endl;
    e = std::move(l2);
    std::cout << "e: " << e << " l2: "<< l2 << std::endl;
    l1[0] = std::move(e[1]);
    std::cout << "l1: " << l1 << " e: "<< e << std::endl;
    */
}