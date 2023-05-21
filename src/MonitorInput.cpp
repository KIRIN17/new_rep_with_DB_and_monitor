#include "MonitorInput.h"

MonitorInput::MonitorInput(std::istream &istream_) : istream(istream_) , echoes() {}

MonitorInput::MonitorInput(std::istream &istream_, std::vector<std::ostream *> echoes_) :
istream(istream_) , echoes(std::move(echoes_)) {}

std::string MonitorInput::getline(){
    std::string result;
    std::getline(istream, result);
    for(const auto &echo : echoes){
        *echo << result << std::endl;
    }
    return result;
}

bool MonitorInput::eof() const{
    return istream.eof();
}

bool MonitorInput::good() const{
    return istream.good();
}
