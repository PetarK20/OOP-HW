#include "Member.h" 
#include <iostream>
#include <stdexcept> 

using namespace std;

Member::Member() : name("Unnamed"), memberID("M000"), yearJoined(2000) {}

Member::Member(string memberName, string id, int joinYear)
    : name(memberName)
{ 
    setMemberID(id);
    setYearJoined(joinYear);
}

string Member::getName() const
{
    return name;
}

string Member::getMemberID() const
{
    return memberID;
}

int Member::getYearJoined() const
{
    return yearJoined;
}

void Member::setName(const string &memberName)
{
    name = memberName;
}

void Member::setMemberID(const string &id)
{
    if (id.empty())
    {
        throw invalid_argument("Member ID cannot be empty.");
    }
    memberID = id;
}

void Member::setYearJoined(int joinYear)
{
    if (joinYear < 1900 || joinYear > 2025)
    {
        throw out_of_range("Year joined must be between 1900 and 2025.");
    }
    yearJoined = joinYear;
}

string Member::to_string() const
{
    return "Member: " + name + ", ID: " + memberID + ", Year Joined: " + std::to_string(yearJoined);
}