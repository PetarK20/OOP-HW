#include "Author.h" 
#include <iostream>
#include <stdexcept> 

using namespace std;

Author::Author() : name("Unknown"), birthYear(1900) {}

Author::Author(string authorName, int year) : name(authorName)
{
    setBirthYear(year);
}

string Author::getName() const
{
    return name;
}

int Author::getBirthYear() const
{
    return birthYear;
}

void Author::setBirthYear(int year)
{
    if (year < 1850 || year > 2025)
    {
        throw out_of_range("Birth year must be between 1850 and 2025.");
    }
    birthYear = year;
}

string Author::to_string() const
{
    return "Author: " + name + " (Born: " + std::to_string(birthYear) + ")";
}