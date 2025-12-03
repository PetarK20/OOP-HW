#include "Library.h" 
#include <iostream>
#include <vector>
#include <string>    
#include <stdexcept> 

using namespace std;

void Library::addBook(const Book &book)
{
    books.push_back(book);
}

void Library::addMember(const Member &member)
{
    if (Library::isMemberTaken(member.getMemberID()))
    {
        cout << "Member with ID " << member.getMemberID() << " already exists. Cannot add duplicate.\n";
        return;
    }
    members.push_back(member);
}

void Library::addLoan(const Loan &loan)
{
    loans.push_back(loan);
}

vector<Book> Library::findBooksByAuthor(const string &authorName) const
{
    vector<Book> result;
    for (const Book &book : books)
    {
        if (book.getAuthor().getName() == authorName)
        {
            result.push_back(book);
        }
    }
    return result;
}

vector<Book> Library::getBooksByYear(int year) const
{
    vector<Book> result;
    for (const Book &book : books)
    {
        if (book.getYear() == year)
        {
            result.push_back(book);
        }
    }
    return result;
}

bool Library::isBookAvailable(const string &isbn) const
{
    if (!Library::hasBook(isbn)) 
    {
        return false;
    }

    for (const Loan &loan : loans)
    {
        if (loan.getIsbn() == isbn && !loan.isReturned())
        {
            return false;
        }
    }

    return true;
}

bool Library::loanBook(const string &isbn, const string &memberID, const string &startDate, const string &dueDate)
{
    if (!Library::isBookAvailable(isbn))
    {
        return false;
    }
    Loan newLoan(isbn, memberID, startDate, dueDate);
    loans.push_back(newLoan);
    return true;
}

bool Library::returnBook(const string &isbn, const string &memberID)
{
    for (Loan &loan : loans)
    {
        if (loan.getIsbn() == isbn && loan.getMemberID() == memberID && !loan.isReturned())
        {
            loan.markReturned(true);
            return true;
        }
    }
    return false;
}

bool Library::hasBook(const string &isbn) const
{
    for (const Book &book : books)
    {
        if (book.getIsbn() == isbn)
        {
            return true;
        }
    }
    return false;
}


bool Library::isMemberTaken(const string &memberID) const
{
    for (const Member &member : members)
    {
        if (member.getMemberID() == memberID)
        {
            return true;
        }
    }
    return false;
}

string Library::to_string() const
{
    string result = "Library contains:\n";
    result += "Books ->\n";
    for (const Book &book : books)
    {
        
        if (Library::isBookAvailable(book.getIsbn()))
        {
            result += book.to_string() + "\n";
        }
        else
        {
            result += "Book unavailable: " + book.getTitle() + " (ISBN: " + book.getIsbn() + ")\n";
        }
    }
    result += "Members ->\n";
    for (const Member &member : members)
    {
        result += "Name: " + member.getName() + ", ID: " + member.getMemberID() + ", Year Joined: " + std::to_string(member.getYearJoined()) + "\n";
    }
    result += "Loans ->\n";
    if (loans.empty())
    {
        result += "No active loans.\n";
    }
    for (const Loan &loan : loans)
    {
        result += loan.to_string() + "\n";
    }
    return result;
}