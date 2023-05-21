#include <gtest/gtest.h>

#include "Monitor.h"
#include "utilFunctions.h"

namespace {
    TEST(toLower, first) {
        std::string str = "Aaaa";
        MonUt::toLower(str);
        EXPECT_EQ(str, "aaaa");
    }

    TEST(toLower, last) {
        std::string str = "AatB";
        MonUt::toLower(str);
        EXPECT_EQ(str, "aatb");
    }

    TEST(toLower, t1) {
        std::string str = "AAbbBBfds AWAD Wa";
        MonUt::toLower(str);
        EXPECT_EQ(str, "aabbbbfds awad wa");
    }

    TEST(toLower, t2) {
        std::string str = "QWE123";
        MonUt::toLower(str);
        EXPECT_EQ(str, "qwe123");
    }

    TEST(toLower, t3) {
        std::string str = "Q";
        MonUt::toLower(str);
        EXPECT_EQ(str, "q");
    }

    TEST(isWhitespace, t1) {
        EXPECT_EQ(MonUt::isWhitespace(' '), true);
    }

    TEST(isWhitespace, t2) {
        EXPECT_EQ(MonUt::isWhitespace('\t'), true);
    }

    TEST(isWhitespace, t3) {
        EXPECT_EQ(MonUt::isWhitespace('a'), false);
    }
}
