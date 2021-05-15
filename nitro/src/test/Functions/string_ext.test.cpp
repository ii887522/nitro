// Copyright ii887522

#ifdef TEST

#include "string_ext.test.h"  // NOLINT(build/include_subdir)
#include <string>
#include <cassert>
#include "../../main/Functions/string_ext.h"

using std::string;

namespace ii887522::nitro {

static void testGetLastPathDelimiterI() {
  assert(getLastPathDelimiterI("a") == string::npos);
  assert(getLastPathDelimiterI("b") == string::npos);
  assert(getLastPathDelimiterI("b/") == 1u);
  assert(getLastPathDelimiterI("b\\") == 1u);
  assert(getLastPathDelimiterI("b\\a") == 1u);
  assert(getLastPathDelimiterI("b\\a\\") == 3u);
  assert(getLastPathDelimiterI("b\\a\\a") == 3u);
  assert(getLastPathDelimiterI("b\\a\\a\\") == 5u);
  assert(getLastPathDelimiterI("b\\a\\a\\a") == 5u);
}

static void testGetFileName() {
  assert(getFileName("a") == "a");
  assert(getFileName("b") == "b");
  assert(getFileName("ba") == "ba");
  assert(getFileName("bb") == "bb");
  assert(getFileName("cb") == "cb");
  assert(getFileName("cba") == "cba");
  assert(getFileName("cbb") == "cbb");
  assert(getFileName("ccb") == "ccb");
  assert(getFileName("dcb") == "dcb");
  assert(getFileName("dcba") == "dcba");
  assert(getFileName("dcba.a") == "dcba");
  assert(getFileName("/cba") == "cba");
  assert(getFileName("\\cba") == "cba");
  assert(getFileName("\\cba.a") == "cba");
  assert(getFileName("\\cba.b") == "cba");
  assert(getFileName("\\cba.ba") == "cba");
  assert(getFileName("\\c\\a.ba") == "a");
}

constexpr static void testToUpperCaseForChar() {
  static_assert(toUpperCase('`') == '`');
  static_assert(toUpperCase('a') == 'A');
  static_assert(toUpperCase('b') == 'B');
  static_assert(toUpperCase('y') == 'Y');
  static_assert(toUpperCase('z') == 'Z');
  static_assert(toUpperCase('{') == '{');
}

constexpr static void testToLowerCaseForChar() {
  static_assert(toLowerCase('@') == '@');
  static_assert(toLowerCase('A') == 'a');
  static_assert(toLowerCase('B') == 'b');
  static_assert(toLowerCase('Y') == 'y');
  static_assert(toLowerCase('Z') == 'z');
  static_assert(toLowerCase('[') == '[');
}

static void testToUpperCaseForString() {
  {
    string str{ "a" };
    toUpperCase(&str);
    assert(str == "A");
  }
  {
    string str{ "b" };
    toUpperCase(&str);
    assert(str == "B");
  }
  {
    string str{ "ba" };
    toUpperCase(&str);
    assert(str == "BA");
  }
  {
    string str{ "bb" };
    toUpperCase(&str);
    assert(str == "BB");
  }
  {
    string str{ "cb" };
    toUpperCase(&str);
    assert(str == "CB");
  }
  {
    string str{ "cba" };
    toUpperCase(&str);
    assert(str == "CBA");
  }
  {
    string str{ "cbb" };
    toUpperCase(&str);
    assert(str == "CBB");
  }
  {
    string str{ "ccb" };
    toUpperCase(&str);
    assert(str == "CCB");
  }
  {
    string str{ "dcb" };
    toUpperCase(&str);
    assert(str == "DCB");
  }
  {
    string str{ "dcba" };
    toUpperCase(&str);
    assert(str == "DCBA");
  }
}

static void testToLowerCaseForString() {
  {
    string str{ "A" };
    toLowerCase(&str);
    assert(str == "a");
  }
  {
    string str{ "B" };
    toLowerCase(&str);
    assert(str == "b");
  }
  {
    string str{ "BA" };
    toLowerCase(&str);
    assert(str == "ba");
  }
  {
    string str{ "BB" };
    toLowerCase(&str);
    assert(str == "bb");
  }
  {
    string str{ "CB" };
    toLowerCase(&str);
    assert(str == "cb");
  }
  {
    string str{ "CBA" };
    toLowerCase(&str);
    assert(str == "cba");
  }
  {
    string str{ "CBB" };
    toLowerCase(&str);
    assert(str == "cbb");
  }
  {
    string str{ "CCB" };
    toLowerCase(&str);
    assert(str == "ccb");
  }
  {
    string str{ "DCB" };
    toLowerCase(&str);
    assert(str == "dcb");
  }
  {
    string str{ "DCBA" };
    toLowerCase(&str);
    assert(str == "dcba");
  }
}

void testStringExt() {
  testGetLastPathDelimiterI();
  testGetFileName();
  testToUpperCaseForChar();
  testToLowerCaseForChar();
  testToUpperCaseForString();
  testToLowerCaseForString();
}

}  // namespace ii887522::nitro

#endif
