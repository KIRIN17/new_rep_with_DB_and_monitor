#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <memory>

using namespace std;

class Date {
public:
    Date(int y,int m,int d);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

    std::string ToString() const;

private:
    int year;
    int month;
    int day;
};

std::ostream& operator << (std::ostream& output,const Date& to_out);

bool operator < (const Date& lhs, const Date& rhs);

bool operator <= (const Date& lhs, const Date& rhs);

bool operator > (const Date& lhs, const Date& rhs);

bool operator >= (const Date& lhs, const Date& rhs);

bool operator == (const Date& lhs, const Date& rhs);

bool operator != (const Date& lhs, const Date& rhs);

Date ParseDate(std::istream& stream);

//std::string ParseEvent(std::istream &is) {
//    std::string res;
//    is >> std::ws;
//    std::getline(is, res);
//    return res;
//}