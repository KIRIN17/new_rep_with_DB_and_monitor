#include <gtest/gtest.h>

#include "TestCommandFactory.hpp"
#include "Init.h"

namespace{
    TEST(parseCommand, inittype){
        std::ostream &ostream = std::cout;
        std::string query = "init";
        TestCommandFactory tcf;

        // test by casting base pointer to derived by dynamic cast
        EXPECT_NE(dynamic_cast<Init *>(tcf.getCommand(query).get()), nullptr);
    }
}
