#ifndef MAIN_MONITORINPUT_H
#define MAIN_MONITORINPUT_H

#include <istream>
#include <vector>

class MonitorInput {
private:
    std::istream &istream;
    std::vector<std::ostream *> echoes;
public:
    explicit MonitorInput(std::istream &istream_);
    MonitorInput(std::istream &istream_, std::vector<std::ostream *> echoes_);

    std::string getline();
    bool eof() const;
    bool good() const;
};


#endif //MAIN_MONITORINPUT_H
