#include <iostream>
#include <fstream>
#include "database.h"
#include <Monitor.h>

#include "MyCommandFactory.hpp"

//#define MONITOR_WITHFILE // Флаг отвечает за ввод команд из текстового файла
/* не забывать добавлять в симейк
 1 RemoveIf(Del) +
 2 FindIf(Find) +
 3 Add +
 4 Last
 5 Print +
*/
int main() {
    system("chcp 65001");
    Database *database = new Database();
    MyCommandFactory<std::tuple<Print, Help, Add, Find, Del, Last>> commandFactory("Example", database);

#ifdef MONITOR_WITHFILE
    std::ifstream istream("exampleInput.txt");
    if(!istream.is_open()){
        throw std::runtime_error("can't find input file");
    }

    std::ofstream ostream("exampleOutput.txt");
    if(!ostream.is_open()){
        throw std::runtime_error("can't find output file");
    }

    Monitor monitor(commandFactory, istream, ostream, true);
#else //MONITOR_WITHFILE
    Monitor monitor(commandFactory, std::cin, std::cout, false);
#endif //MONITOR_WITHFILE

    monitor.run();

    return 0;
}
