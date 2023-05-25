#pragma once
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "node.h"
#include "./functions.h"

template <typename T>
ostream& operator << (ostream& out, const vector<T> v){
    out << "{ ";
    for(const T& elem : v)
        out << elem << ' ';
    out << "}";
    return out;
}
class Database {
public:
    //шаблонные функции реализуются в заголовочном файле!
    template <typename T> int RemoveIf(T predicate) {//в предикат нужно передавать параметры?
        int count = 0;
        for(auto i = ALL_DATA.begin();i != ALL_DATA.end(); ++i){
            Date tmp = i->first;
            auto it = stable_partition(ALL_DATA[i->first].begin(),ALL_DATA[i->first].end(),[predicate,tmp](const string& s){
                return predicate(tmp,s);
            });

            for(auto j = ALL_DATA[i->first].begin();j != it;++j){
                ALL_DATA_SET[i->first].erase(*j);
            }

            int size_1 = ALL_DATA.at(i->first).size();
            ALL_DATA[i->first].erase(ALL_DATA[i->first].begin(),it);
            int size_2 = ALL_DATA.at(i->first).size();
            count += size_1 - size_2;

        }
        for(auto i = ALL_DATA.begin();i != ALL_DATA.end();){//удаление пустых дат
            if(ALL_DATA.at(i->first).empty()){
                i = ALL_DATA.erase(i);
            }
            else{
                ++i;
            }
        }

        for(auto i = ALL_DATA_SET.begin();i != ALL_DATA_SET.end();){//удаление пустых дат
            if(!ALL_DATA.count(i->first)){
                i = ALL_DATA_SET.erase(i);
            }
            else{
                ++i;
            }
        }

        return count;
    }

    std::map<Date,std::vector<std::string>> get_ALL_DATA() const;
    std::map<Date,std::set<std::string>> get_ALL_DATA_SET();

    void set_to_ALL_DATA(const Date& date, const std::string& event);
    void set_to_ALL_DATA_SET(const Date& date, const std::string& event);

private:
    std::map<Date,std::vector<std::string>> ALL_DATA;
    std::map<Date,std::set<std::string>> ALL_DATA_SET;

};