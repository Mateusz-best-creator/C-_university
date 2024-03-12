#include "library.h"
#include <iostream>

Library::Library(std::initializer_list<Book> list)
{
    size = list.size();
    array = new Book[size];
    std::copy(list.begin(), list.end(), array);
}

Library::Library(const Library& orig)
{
    size = orig.size;
    array = new Book[size];
    std::copy(orig.array, orig.array + size, array);
}

Library::Library(Library&& orig)
{
    size = orig.size;
    array = orig.array;
    orig.array = nullptr;
    orig.size = 0;
}

Library::~Library()
{
    delete[] array;
}

Library& Library::operator=(const Library& right)
{
    if (this == &right)
        return *this;
    delete[] array;
    size = right.size;
    std::copy(right.array, right.array + size, array);
    return *this;
}

Library& Library::operator=(Library&& right)
{
    if (this == &right)
        return *this;
    delete[] array;
    array = right.array;
    size = right.size;
    right.array = nullptr;
    right.size = 0;
    return *this;
}

Book& Library::operator[](std::size_t index)
{
    return array[index];
}

const Book& Library::operator[](std::size_t index) const
{
    return array[index];
}

std::size_t Library::GetSize() const
{
    return size;
}

//Only for the list implementation
void Library::push_back(const Book& book)
{
    Book* newArray = new Book[size + 1];
    std::copy(array, array + size, newArray);
    newArray[size++] = book;
    delete[] array;
    array = newArray;
}

void Library::push_back(Book&& book)
{
    Book* newArray = new Book[size + 1];
    std::copy(array, array + size, newArray);
    newArray[size++] = std::move(book);
    delete[] array;
    array = newArray;
}

Book Library::pop_back()
{
    Book poppedBook = std::move(array[size - 1]);
    --size;
    return poppedBook;
}

std::ostream& operator<<(std::ostream& os, const Library& lib) 
{
    os << "Library: \n";
    for (int i = 0; i < lib.size; i++) {
        os << lib.array[i] << ", ";
    }
    os << "\n";
    return os;
}
