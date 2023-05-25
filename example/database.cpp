#include "database.h"
#include <fstream>

std::map<Date,std::vector<std::string>> Database::get_ALL_DATA()const{return ALL_DATA;}
std::map<Date,std::set<std::string>> Database::get_ALL_DATA_SET(){return ALL_DATA_SET;}

void Database::set_to_ALL_DATA(const Date& date, const std::string& event){
    ALL_DATA[date].push_back(event);
}
void Database::set_to_ALL_DATA_SET(const Date& date, const std::string& event){
    ALL_DATA_SET[date].insert(event);
}
