#ifndef MAIN_MONITORHELP_H
#define MAIN_MONITORHELP_H

#include <map>

class MonitorHelp {
private:
    static constexpr char message[] = "monitor help";
public:
    static const char *getMessage(){
        return message;
    }
};

#endif //MAIN_MONITORHELP_H
