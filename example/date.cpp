#include "date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}

int Date::GetYear() const{return year;}
int Date::GetMonth() const{return month;}
int Date::GetDay() const{return day;}

void Date::SetData(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

std::string Date::ToString() const{
    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year << '-' <<
       std::setw(2) << std::setfill('0') << month << '-' <<
       std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

std::ostream& operator << (std::ostream& output,const Date& to_out){
    output << std::setw(4) << std::setfill('0') << to_out.GetYear() << '-' <<
           std::setw(2) << std::setfill('0') << to_out.GetMonth() << '-' <<
           std::setw(2) << std::setfill('0') << to_out.GetDay();
    return output;
}

bool operator < (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) < std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

bool operator <= (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) <= std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

bool operator > (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) > std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

bool operator >= (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) >= std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

bool operator == (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) == std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

bool operator != (const Date& lhs, const Date& rhs){
    return std::make_tuple(lhs.GetYear(),lhs.GetMonth(),lhs.GetDay()) != std::make_tuple(rhs.GetYear(),rhs.GetMonth(),rhs.GetDay());
}

Date ParseDate(std::istream& stream){

    int y,m,d;
    if(stream >> y && stream.get() == '-' && stream >> m && stream.get() == '-' && stream >> d && (stream.peek() == ' ' || stream.peek() == EOF)){
        if(((m < 1 || m > 12) && (d < 1 || d > 31)) || (m < 1 || m > 12)){
            //throw std::runtime_error("Month value is invalid: " + std::to_string(m));
            std::cout<<"Month value is invalid: " << std::to_string(m);
            return {-1,-1,-1};
            //return stream;
        }else{
            if(d < 1 || d > 31){
                //throw std::runtime_error("Day value is invalid: " + std::to_string(d));
                std::cout << "Day value is invalid: " << std::to_string(d);
                return {-1,-1,-1};
            }else{
                return {y,m,d};
            }
        }
    }else{
        std::cout << "Wrong date format\n";
        return {-1,-1,-1};
    }
}