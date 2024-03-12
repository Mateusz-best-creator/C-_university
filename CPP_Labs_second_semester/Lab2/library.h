#pragma once

#include "book.h"
#include <initializer_list>

class Library 
{
private:
    Book* array;
    size_t size = 0;

public:
    Library() = default;
    Library(std::initializer_list<Book> list);
    Library(const Library& orig);
    Library(Library&& orig);
    ~Library();


    Library& operator=(const Library& right);
    Library& operator=(Library&& right);
    Book& operator[](std::size_t index);
    const Book& operator[](std::size_t index) const;
    std::size_t GetSize() const;
   

    //Only for the list implementation
    void push_back(const Book&);
    void push_back(Book&&);
    Book pop_back();

    friend std::ostream& operator<<(std::ostream& os, const Library& lib);
};