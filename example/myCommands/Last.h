//#ifndef MAIN_HELP_H
//#define MAIN_HELP_H

#include <utility>
#include "../database.h"
#include "BaseCommand.h"

class Last : public BaseCommand {
private:
    Date date;
    Database* database;
    std::string inner;

    static constexpr char helpMessage[] = "";
protected:
    std::string help() override;
public:

    Last(std::string string, Database* database);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

//#endif //MAIN_HELP_H
