#include "book.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "\nBook title = " << book.title << "\n";
    os << "Book author = " << book.author << "\n";
    return os;
}

// Move semantics
Book::Book(const Book& other)
{
    author = other.author;
    title = other.title;
}

Book::Book(const Book&& other) noexcept
{
    author = std::move(other.author);
    title = std::move(other.title);
}

Book& Book::operator=(const Book& other)
{
    if (this == &other)
        return *this;
    author = other.author;
    title = other.title;
    return *this;
}
Book& Book::operator=(const Book&& other) noexcept
{
    author = std::move(other.author);
    title = std::move(other.title);
    return*this;
}