//#ifndef MAIN_HELP_H
//#define MAIN_HELP_H

#include <utility>
#include "../database.h"
#include "BaseCommand.h"

std::string ToStringDB(Database* database);

std::string ToStringVector(const Date& date,std::string nums,const Database* database);

class Print : public BaseCommand {
private:
    Database* database;
    std::string inner;

    static constexpr char helpMessage[] = "";
protected:
    std::string help() override;
public:
    //explicit Print(std::string string);
    Print(std::string string, Database* database);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

//#endif //MAIN_HELP_H
