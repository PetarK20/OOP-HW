#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library
{
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book &book);
    void addMember(const Member &member);
    void addLoan(const Loan &loan);

    std::vector<Book> findBooksByAuthor(const std::string &authorName) const;
    std::vector<Book> getBooksByYear(int year) const;

    bool isBookAvailable(const std::string &isbn) const;
    bool hasBook(const std::string &isbn) const;
    bool isMemberTaken(const std::string &memberID) const;

    bool loanBook(const std::string &isbn, const std::string &memberID, const std::string &startDate, const std::string &dueDate);
    bool returnBook(const std::string &isbn, const std::string &memberID);

    std::string to_string() const;
};