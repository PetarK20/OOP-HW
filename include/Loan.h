#pragma once
#include <string>
#include <iostream>

class Loan {
private:
    std::string isbn;
    std::string memberID;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan();
    Loan(std::string bookIsbn, std::string memID, std::string start, std::string due);

    std::string getIsbn() const;
    std::string getMemberID() const;
    std::string getStartDate() const;
    std::string getDueDate() const;
    bool isReturned() const;

    void markReturned(bool status);
    bool isOverdue(const std::string &currentDate) const;

    std::string to_string() const;
};