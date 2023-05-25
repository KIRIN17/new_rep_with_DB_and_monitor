#pragma once

#include "node.h"

#include <iostream>

using namespace std;

//shared_ptr<Node> ParseCondition(istream& is);
shared_ptr<Node> ParseCondition(string is);

void TestParseCondition();
