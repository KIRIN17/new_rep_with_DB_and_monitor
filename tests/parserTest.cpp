#include <gtest/gtest.h>

#include "Parser.h"
#include "ParserException.h"

namespace{
    class ParserTest : public Parser{
    public:
        static std::string parseWordTest(const std::string &input, size_t &index){
            return parseWord(input, index);
        }
        static keyArgs_t::key_type parseKeyTest(const std::string &input, size_t &index){
            return parseKey(input, index);
        }
        static keyArgs_t::mapped_type parseKeyValueTest(const std::string &input, size_t &index){
            return parseKeyValue(input, index);
        }
    };

    TEST(parseKey, long1){
        size_t index = 0;
        std::string query = "--init -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "init");
    }

    TEST(parseKey, long2){
        size_t index = 2;
        std::string query = "o --init -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "init");
    }

    TEST(parseKey, long3){
        size_t index = 5;
        std::string query = "init --init -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "init");
    }

    TEST(parseKey, short1){
        size_t index = 0;
        std::string query = "-i -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "i");
    }

    TEST(parseKey, short2){
        size_t index = 2;
        std::string query = "o -i -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "i");
    }

    TEST(parseKey, short3){
        size_t index = 5;
        std::string query = "init -i -b";

        std::string key = ParserTest::parseKeyTest(query, index);
        EXPECT_EQ(key, "i");
    }

    TEST(parseKeyValue, correct1){
        size_t index = 7;
        std::string query = "--init 1";

        auto value = ParserTest::parseKeyValueTest(query, index);
        EXPECT_EQ(value, "1");
    }

    TEST(parseKeyValue, correct2){
        size_t index = 7;
        std::string query = "--init 10 ";

        auto value = ParserTest::parseKeyValueTest(query, index);
        EXPECT_EQ(value, "10");
    }

    TEST(parseKeyValue, correct3){
        size_t index = 7;
        std::string query = "--init 0123456789 -b ";

        auto value = ParserTest::parseKeyValueTest(query, index);
        EXPECT_EQ(value, "0123456789");
    }

    // deprecated
//    TEST(parseKeyValue, throwing_outofrange1){
//        size_t index = 7;
//        std::string query = "--init 0123456789123456789 -b ";
//
//        EXPECT_THROW(ParserTest::parseKeyValueTest(query, index), ParserException);
//    }
//
//    TEST(parseKeyValue, throwing_outofrange2){
//        size_t index = 7;
//        std::string query = "--init 0009999999999 -b ";
//
//        EXPECT_THROW(ParserTest::parseKeyValueTest(query, index), ParserException);
//    }
//
//    TEST(parseKeyValue, throwing_invalidvalue1){
//        size_t index = 7;
//        std::string query = "--init invalid -b ";
//
//        EXPECT_THROW(ParserTest::parseKeyValueTest(query, index), ParserException);
//    }
//
//    TEST(parseKeyValue, throwing_invalidvalue2){
//        size_t index = 7;
//        std::string query = "--init -invalid -b ";
//
//        EXPECT_THROW(ParserTest::parseKeyValueTest(query, index), ParserException);
//    }

    TEST(parseWord, atBeginning){
        size_t index = 0;
        std::string query = "word -b ";

        std::string value = ParserTest::parseWordTest(query, index);
        EXPECT_EQ(value, "word");
    }

    TEST(parseWord, atEnd){
        size_t index = 7;
        std::string query = "word -b ";

        EXPECT_THROW(ParserTest::parseWordTest(query, index), ParserException);
    }

    TEST(parseWord, t1){
        size_t index = 1;
        std::string query = " word -b ";

        std::string value = ParserTest::parseWordTest(query, index);
        EXPECT_EQ(value, "word");
    }

    TEST(parseWord, t2){
        size_t index = 3;
        std::string query = "as word -b ";

        std::string value = ParserTest::parseWordTest(query, index);
        EXPECT_EQ(value, "word");
    }

    TEST(parseWord, with_kavichki_correct){
        size_t index = 3;
        std::string query = "as \"word\" -b ";

        std::string value = ParserTest::parseWordTest(query, index);
        EXPECT_EQ(value, "word");
    }

    TEST(parseWord, with_kavichki_invalid){
        size_t index = 3;
        std::string query = "as \"word -b ";

        EXPECT_THROW(ParserTest::parseWordTest(query, index), ParserException);
    }

    TEST(parseKey, single_dash){
        std::string query = "full -e";
        EXPECT_NO_THROW(Parser(std::ref(query)));
    }
}