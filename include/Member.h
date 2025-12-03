#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Member
{
private:
    std::string name;
    std::string memberID;
    int yearJoined;

public:
    Member();
    Member(std::string memberName, std::string id, int joinYear);

    std::string getName() const;
    std::string getMemberID() const;
    int getYearJoined() const;

    void setName(const std::string &memberName);
    void setMemberID(const std::string &id);
    void setYearJoined(int joinYear);

    std::string to_string() const;
};