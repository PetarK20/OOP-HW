#include <iostream>
#include <stdexcept>   
using namespace std;
#include "Book.h"

int Book::totalBooks = 0;

Book::Book() : title("Untitled"), author(), year(2000), price(0.0), isbn("000-0-00-000000-0")
{
    ++totalBooks;
}

Book::Book(string bookTitle, Author bookAuthor, int pubYear, double bookPrice, string bookIsbn)
    : title(bookTitle), author(bookAuthor), isbn(bookIsbn)
{
    setYear(pubYear);
    setPrice(bookPrice);
    ++totalBooks;
}

Book::Book(const Book &other)
    : title(other.title),
      author(other.author),
      year(other.year),
      price(other.price),
      isbn(other.isbn)
{
    ++totalBooks;
}

Book::Book(Book &&other) noexcept
    : title(move(other.title)),
      author(move(other.author)),
      year(other.year),
      price(other.price),
      isbn(move(other.isbn)) {}

Book& Book::operator=(const Book &other)
{
    if (this != &other)
    {
        title = other.title;
        author = other.author;
        year = other.year;
        price = other.price;
        isbn = other.isbn;
    }

    return *this;
}

Book& Book::operator=(Book &&other) noexcept
{

    if (this != &other)
    {
        title = move(other.title);
        author = move(other.author);
        year = other.year;
        price = other.price;
        isbn = move(other.isbn);

        other.title = "";
        other.isbn = "";
        other.year = 0;
        other.price = 0.0;
        other.author = Author();
    }

    return *this;
}

Book::~Book()
{
    --totalBooks;
}

void Book::setPrice(double bookPrice)
{
    if (bookPrice < 0.0)
    {
        throw invalid_argument("Price cannot be negative.");
    }
    price = bookPrice;
}

void Book::setYear(int pubYear)
{
    if (pubYear < 1000 || pubYear > 2025)
    {
        throw out_of_range("Publication year must be between 1000 and 2025.");
    }
    year = pubYear;
}
void Book::setTitle(const string &t)
{
    title = t;
}
void Book::setIsbn(const string &i)
{
    isbn = i;
}

void Book::setAuthor(const Author &a)
{
    author = a;
}

Author Book::getAuthor() const
{
    return author;
}

string Book::getTitle() const
{
    return title;
}

string Book::getIsbn() const
{
    return isbn;
}

int Book::getYear() const
{
    return year;
}

double Book::getPrice() const
{
    return price;
}

int Book::getTotalBooks()
{
    return totalBooks;
}

string Book::to_string() const
{
    return "Title: " + title + "\n" +
           author.to_string() + "\n" +
           "Year: " + std::to_string(year) + "\n" +
           "Price: " + std::to_string(price) + "\n" +
           "ISBN: " + isbn + "\n";
}
