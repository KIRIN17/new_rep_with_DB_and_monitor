#ifndef MAIN_MONITOROUTPUT_H
#define MAIN_MONITOROUTPUT_H

#include <ostream>
#include <vector>

class MonitorOutput {
private:
    std::vector<std::ostream *> ostreams;
public:
    MonitorOutput(std::ostream &ostream_);
    MonitorOutput(std::ostream &ostream_, std::ostream &echo_);

    MonitorOutput &operator<<(const std::string &message);
    MonitorOutput &operator<<(const char *message);
};


#endif //MAIN_MONITOROUTPUT_H
