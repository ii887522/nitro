// Copyright ii887522

#ifdef TEST

#include <string>
#include <catch.hpp>
#include "../../main/Functions/string_ext.h"

using std::string;

namespace ii887522::nitro {

TEST_CASE("test getLastPathDelimiterI() function") {
  REQUIRE(getLastPathDelimiterI("a") == string::npos);
  REQUIRE(getLastPathDelimiterI("b") == string::npos);
  REQUIRE(getLastPathDelimiterI("b/") == 1u);
  REQUIRE(getLastPathDelimiterI("b\\") == 1u);
  REQUIRE(getLastPathDelimiterI("b\\a") == 1u);
  REQUIRE(getLastPathDelimiterI("b\\a\\") == 3u);
  REQUIRE(getLastPathDelimiterI("b\\a\\a") == 3u);
  REQUIRE(getLastPathDelimiterI("b\\a\\a\\") == 5u);
  REQUIRE(getLastPathDelimiterI("b\\a\\a\\a") == 5u);
}

TEST_CASE("test getFileName() function") {
  REQUIRE(getFileName("a") == "a");
  REQUIRE(getFileName("b") == "b");
  REQUIRE(getFileName("ba") == "ba");
  REQUIRE(getFileName("bb") == "bb");
  REQUIRE(getFileName("cb") == "cb");
  REQUIRE(getFileName("cba") == "cba");
  REQUIRE(getFileName("cbb") == "cbb");
  REQUIRE(getFileName("ccb") == "ccb");
  REQUIRE(getFileName("dcb") == "dcb");
  REQUIRE(getFileName("dcba") == "dcba");
  REQUIRE(getFileName("dcba.a") == "dcba");
  REQUIRE(getFileName("/cba") == "cba");
  REQUIRE(getFileName("\\cba") == "cba");
  REQUIRE(getFileName("\\cba.a") == "cba");
  REQUIRE(getFileName("\\cba.b") == "cba");
  REQUIRE(getFileName("\\cba.ba") == "cba");
  REQUIRE(getFileName("\\c\\a.ba") == "a");
}

TEST_CASE("test toUpperCase(const char) function") {
  REQUIRE(toUpperCase('`') == '`');
  REQUIRE(toUpperCase('a') == 'A');
  REQUIRE(toUpperCase('b') == 'B');
  REQUIRE(toUpperCase('y') == 'Y');
  REQUIRE(toUpperCase('z') == 'Z');
  REQUIRE(toUpperCase('{') == '{');
}

TEST_CASE("test toLowerCase(const char) function") {
  REQUIRE(toLowerCase('@') == '@');
  REQUIRE(toLowerCase('A') == 'a');
  REQUIRE(toLowerCase('B') == 'b');
  REQUIRE(toLowerCase('Y') == 'y');
  REQUIRE(toLowerCase('Z') == 'z');
  REQUIRE(toLowerCase('[') == '[');
}

TEST_CASE("test toUpperCase(string*const) function") {
  {
    string str{ "a" };
    toUpperCase(&str);
    REQUIRE(str == "A");
  }
  {
    string str{ "b" };
    toUpperCase(&str);
    REQUIRE(str == "B");
  }
  {
    string str{ "ba" };
    toUpperCase(&str);
    REQUIRE(str == "BA");
  }
  {
    string str{ "bb" };
    toUpperCase(&str);
    REQUIRE(str == "BB");
  }
  {
    string str{ "cb" };
    toUpperCase(&str);
    REQUIRE(str == "CB");
  }
  {
    string str{ "cba" };
    toUpperCase(&str);
    REQUIRE(str == "CBA");
  }
  {
    string str{ "cbb" };
    toUpperCase(&str);
    REQUIRE(str == "CBB");
  }
  {
    string str{ "ccb" };
    toUpperCase(&str);
    REQUIRE(str == "CCB");
  }
  {
    string str{ "dcb" };
    toUpperCase(&str);
    REQUIRE(str == "DCB");
  }
  {
    string str{ "dcba" };
    toUpperCase(&str);
    REQUIRE(str == "DCBA");
  }
}

TEST_CASE("test toLowerCase(string*const) function") {
  {
    string str{ "A" };
    toLowerCase(&str);
    REQUIRE(str == "a");
  }
  {
    string str{ "B" };
    toLowerCase(&str);
    REQUIRE(str == "b");
  }
  {
    string str{ "BA" };
    toLowerCase(&str);
    REQUIRE(str == "ba");
  }
  {
    string str{ "BB" };
    toLowerCase(&str);
    REQUIRE(str == "bb");
  }
  {
    string str{ "CB" };
    toLowerCase(&str);
    REQUIRE(str == "cb");
  }
  {
    string str{ "CBA" };
    toLowerCase(&str);
    REQUIRE(str == "cba");
  }
  {
    string str{ "CBB" };
    toLowerCase(&str);
    REQUIRE(str == "cbb");
  }
  {
    string str{ "CCB" };
    toLowerCase(&str);
    REQUIRE(str == "ccb");
  }
  {
    string str{ "DCB" };
    toLowerCase(&str);
    REQUIRE(str == "dcb");
  }
  {
    string str{ "DCBA" };
    toLowerCase(&str);
    REQUIRE(str == "dcba");
  }
}

}  // namespace ii887522::nitro

#endif
