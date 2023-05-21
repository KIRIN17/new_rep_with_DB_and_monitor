#include "utilFunctions.h"
#include "ParserException.h"
#include "BaseCommand.h"

BaseCommand::BaseCommand() = default;

std::string BaseCommand::processQuery(Parser &parser) {
    auto poss = parser.getBoolArgs();
    std::string resultMessage;

    if(std::find(std::begin(poss), std::end(poss), "help") != std::end(poss)){
        return help();
    } else if(resultMessage = checkAndAssemble(parser); resultMessage.empty()) { // parser becomes invalid here, if no error
        resultMessage = run();
    } else{
        resultMessage += '\n';
        resultMessage += help();
    }

    return resultMessage;
}
