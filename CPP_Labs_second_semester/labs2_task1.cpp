#include <iostream>
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

    friend std::ostream& operator<<(std::ostream& os, const Book& book)
    {
        os << "\nBook title = " << book.title << "\n";
        os << "Book author = " << book.author << "\n";
        return os;
    }

    // Move semantics
    Book(const Book& other)
    {
        author = other.author;
        title = other.title;
    }

    Book(const Book&& other) noexcept
    {
        author = std::move(other.author);
        title = std::move(other.title);
    }

    Book& operator=(const Book& other)
    {
        if (this == &other)
            return *this;
        author = other.author;
        title = other.title;
        return *this;
    }
    Book& operator=(const Book&& other) noexcept
    {
        author = std::move(other.author);
        title = std::move(other.title);
        return*this;
    }
};

int main()
{
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
}