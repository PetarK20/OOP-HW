#pragma once
#include <string>
#include <iostream>
#include "Author.h" 

class Book
{
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;
    static int totalBooks; 

public:
    Book();
    Book(std::string bookTitle, Author bookAuthor, int pubYear, double bookPrice, std::string bookIsbn);
    Book(const Book &other); 
    Book(Book &&other) noexcept; 
    Book &operator=(const Book &other); 
    Book &operator=(Book &&other) noexcept; 
    ~Book();

    void setPrice(double bookPrice);
    void setYear(int pubYear);
    void setTitle(const std::string &t);
    void setIsbn(const std::string &i);
    void setAuthor(const Author &a);

    Author getAuthor() const;
    std::string getTitle() const;
    std::string getIsbn() const;
    int getYear() const;
    double getPrice() const;

    static int getTotalBooks();
    std::string to_string() const;
};