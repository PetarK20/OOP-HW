#include "Loan.h" 
#include <iostream>
#include <stdexcept> 

using namespace std;

Loan::Loan() : isbn("ISBN-000"), memberID("0000"), startDate("1970-01-01"), dueDate("1970-01-01"), returned(false) {}

Loan::Loan(string bookIsbn, string memID, string start, string due)
    : isbn(bookIsbn), memberID(memID), startDate(start), dueDate(due), returned(false)
{
    if (dueDate < startDate) {
        throw invalid_argument("dueDate cannot be before startDate");
    }
}

string Loan::getIsbn() const
{
    return isbn;
}

string Loan::getMemberID() const
{
    return memberID;
}

string Loan::getStartDate() const
{
    return startDate;
}

string Loan::getDueDate() const
{
    return dueDate;
}

bool Loan::isReturned() const
{
    return returned;
}

void Loan::markReturned(bool status)
{
    returned = status;
}

bool Loan::isOverdue(const string &currentDate) const
{
    return currentDate > dueDate && !returned;
}

string Loan::to_string() const
{
    return "ISBN: " + isbn + "\n" +
           "Member ID: " + memberID + "\n" +
           "Start Date: " + startDate + "\n" +
           "Due Date: " + dueDate + "\n" +
           "Returned: " + (returned ? "Yes" : "No");
}