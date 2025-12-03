#pragma once
#include <string>
#include <iostream>

class Author
{
private:
    std::string name;
    int birthYear;

public:
    Author();
    Author(std::string authorName, int year);

    std::string getName() const;
    int getBirthYear() const;
    void setBirthYear(int year);
    std::string to_string() const;
};