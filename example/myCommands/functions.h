#pragma once
#include <string>
#include <vector>
#include "../database.h"

template <typename T> vector<string> FindIf(T predicate,std::map<Date,std::vector<std::string>> ALL_DATA){
    vector<string> res;

    for(const pair<Date,vector<string>>& p : ALL_DATA){
        Date tmp = p.first;
        size_t size_1 = res.size();

        copy_if(p.second.begin(),p.second.end(),back_inserter(res),[predicate,tmp](const string& s){
            return predicate(tmp,s);
        });

        size_t size_2 = res.size();

        if(size_1 != size_2){//добавление данной даты к каждому новому добавленному событию
            for (int i = size_1; i < size_2; ++i) {
                res[i] = tmp.ToString() + " " + res[i];
            }
        }

    }
    return res;
}

//template <typename T> int RemoveIf(T predicate,) {//в предикат нужно передавать параметры?
//    int count = 0;
//    for(auto i = ALL_DATA.begin();i != ALL_DATA.end(); ++i){
//        Date tmp = i->first;
//        auto it = stable_partition(ALL_DATA[i->first].begin(),ALL_DATA[i->first].end(),[predicate,tmp](const string& s){
//            return predicate(tmp,s);
//        });
//
//        for(auto j = ALL_DATA[i->first].begin();j != it;++j){
//            ALL_DATA_SET[i->first].erase(*j);
//        }
//
//        int size_1 = ALL_DATA.at(i->first).size();
//        ALL_DATA[i->first].erase(ALL_DATA[i->first].begin(),it);
//        int size_2 = ALL_DATA.at(i->first).size();
//        count += size_1 - size_2;
//
//    }
//    for(auto i = ALL_DATA.begin();i != ALL_DATA.end();){//удаление пустых дат
//        if(ALL_DATA.at(i->first).empty()){
//            i = ALL_DATA.erase(i);
//        }
//        else{
//            ++i;
//        }
//    }
//
//
//    for(auto i = ALL_DATA_SET.begin();i != ALL_DATA_SET.end();){//удаление пустых дат
//        if(!ALL_DATA.count(i->first)){
//            i = ALL_DATA_SET.erase(i);
//        }
//        else{
//            ++i;
//        }
//    }
//
//    return count;
//}