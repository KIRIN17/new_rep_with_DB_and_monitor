#include "MonitorOutput.h"

MonitorOutput::MonitorOutput(std::ostream &ostream_) {
    ostreams.resize(1);
    ostreams[0] = &ostream_;
}

MonitorOutput::MonitorOutput(std::ostream &ostream_, std::ostream &echo_) {
    ostreams.resize(2);
    ostreams[0] = &ostream_;
    ostreams[1] = &echo_;
}

MonitorOutput &MonitorOutput::operator<<(const std::string &message) {
    for(const auto ostream : ostreams){
        *ostream << message;
    }
    return *this;
}

MonitorOutput &MonitorOutput::operator<<(const char *message) {
    for(const auto ostream : ostreams){
        *ostream << message;
    }
    return *this;
}
