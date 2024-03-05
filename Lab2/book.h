#pragma once

#include <string>

class Book
{
private:
    std::string author, title;

public:
    Book() = default;
    Book(const std::string& a, const std::string& t)
        : author(a), title(t) {}
    Book(const std::string&& a, const std::string&& t)
        : author(a), title(t) {}
    
    // getters and setters
    const std::string& get_author() const { return author; }
    std::string& get_author() { return author; }
    const std::string& get_title() const { return title; }
    std::string& get_title() { return title; }

    // setters (for task)
    void set_author(const std::string& t) { author = t; }
    void set_title(const std::string& a) { title = a; }
    void set_author(const std::string&& t) { author = std::move(t); }
    void set_title(const std::string&& a) { title = std::move(a); }

    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    // Move semantics
    Book(const Book& other);

    Book(const Book&& other) noexcept;

    Book& operator=(const Book& other);
    
    Book& operator=(const Book&& other) noexcept;
};