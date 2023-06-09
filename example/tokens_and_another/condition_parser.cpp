#include "condition_parser.h"
#include "token.h"
#include <map>


template <class It> shared_ptr<Node> ParseComparison(It& current, It end) {
    if (current == end) {
        //throw logic_error("Expected column name: date or event");
        cout << "Expected column name: date or event";
        return nullptr;
    }

    Token& column = *current;
    if (column.type != TokenType::COLUMN) {
        cout << "Expected column name: date or event";
        return nullptr;
    }
    ++current;

    if (current == end) {
        cout << "Expected comparison operation";
        return nullptr;
    }

    Token& op = *current;
    if (op.type != TokenType::COMPARE_OP) {
        cout << "Expected comparison operation";
        return nullptr;
    }
    ++current;

    if (current == end) {
        cout << "Expected right value of comparison";
        return nullptr;
    }

    Comparison cmp;
    if (op.value == "<") {
        cmp = Comparison::Less;
    } else if (op.value == "<=") {
        cmp = Comparison::LessOrEqual;
    } else if (op.value == ">") {
        cmp = Comparison::Greater;
    } else if (op.value == ">=") {
        cmp = Comparison::GreaterOrEqual;
    } else if (op.value == "==") {
        cmp = Comparison::Equal;
    } else if (op.value == "!=") {
        cmp = Comparison::NotEqual;
    } else {
        cout << "Unknown comparison token: " << op.value;
        return nullptr;
    }

    const string& value = current->value;
    ++current;

    if (column.value == "date") {
        //istringstream is(value);
        //Date tmp;

        return make_shared<DateComparisonNode>(cmp, ParseDate(value));
    } else {
        return make_shared<EventComparisonNode>(cmp, value);
    }
}

template <class It>
shared_ptr<Node> ParseExpression(It& current, It end, unsigned precedence) {
    if (current == end) {
        return shared_ptr<Node>();
    }

    shared_ptr<Node> left;

    if (current->type == TokenType::PAREN_LEFT) {
        ++current; // consume '('
        left = ParseExpression(current, end, 0u);
        if (current == end || current->type != TokenType::PAREN_RIGHT) {
            //throw logic_error("Missing right paren");
            cout << "Missing right paren";
            return nullptr;
        }
        ++current; // consume ')'
    } else {
        left = ParseComparison(current, end);
    }

    const map<LogicalOperation, unsigned> precedences = {
            {LogicalOperation::Or, 1}, {LogicalOperation::And, 2}
    };

    while (current != end && current->type != TokenType::PAREN_RIGHT) {
        if (current->type != TokenType::LOGICAL_OP) {
            cout << "Expected logic operation";
            return nullptr;
        }

        const auto logical_operation = current->value == "AND" ? LogicalOperation::And
                                                               : LogicalOperation::Or;
        const auto current_precedence = precedences.at(logical_operation);
        if (current_precedence <= precedence) {
            break;
        }

        ++current; // consume op

        left = make_shared<LogicalOperationNode>(
                logical_operation, left, ParseExpression(current, end, current_precedence)
        );
    }

    return left;
}

shared_ptr<Node> ParseCondition(string is) {
    auto tokens = Tokenize(is);
    if(!tokens.empty()){
        auto current = tokens.begin();
        auto top_node = ParseExpression(current, tokens.end(), 0u);

        if (!top_node) {
            top_node = make_shared<EmptyNode>();
        }
        if (current != tokens.end()) {
            //throw logic_error("Unexpected tokens after condition");
            cout << "Unexpected tokens after condition";
            return nullptr;
        }
        return top_node;
    }
    else
        return nullptr;
}
