// Copyright ii887522

#ifdef TEST

#include <vector>
#include <fstream>
#include <filesystem>
#include <catch.hpp>
#include "../../main/Functions/fs_ext.h"
#include "../../main/Struct/Range.h"

using std::vector;
using std::ios;
using std::filesystem::create_directory;
using std::filesystem::remove_all;

namespace ii887522::nitro {

TEST_CASE("test fs_ext.h") {
  create_directory("res/test/a/");
  SECTION("test read() function") {
    REQUIRE_THROWS_AS((read<char, vector>("a")), ios::failure);
    REQUIRE((read<char, vector>("res/test/a.dat").size() == 0u));
    {
      const vector<char> str{ read<char, vector>("res/test/b.dat") };
      REQUIRE(str.size() == 3u);
      REQUIRE(str[0u] == 'a');
      REQUIRE(str[1u] == '\r');
      REQUIRE(str[2u] == '\n');
    }
    {
      const vector<char> str{ read<char, vector>("res/test/c.dat") };
      REQUIRE(str.size() == 4u);
      REQUIRE(str[0u] == 'a');
      REQUIRE(str[1u] == 'b');
      REQUIRE(str[2u] == '\r');
      REQUIRE(str[3u] == '\n');
    }
    {
      const vector<unsigned int> ns{ read<unsigned int, vector>("res/test/d.dat") };
      REQUIRE(ns.size() == 1u);
      REQUIRE(ns[0u] == 56271439);
    }
    {
      const vector<unsigned int> ns{ read<unsigned int, vector>("res/test/e.dat") };
      REQUIRE(ns.size() == 2u);
      REQUIRE(ns[0u] == 56271439);
      REQUIRE(ns[1u] == 97025014);
    }
  }
  SECTION("test write() function") {
    write<Range<unsigned int>, vector>("res/test/f.dat", vector<Range<unsigned int>>{ });
    REQUIRE((read<Range<unsigned int>, vector>("res/test/f.dat").size() == 0u));
    {
      write<Range<unsigned int>, vector>("res/test/g.dat", vector{ Range{ 0u, 0u } });
      const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/g.dat") };
      REQUIRE(ranges.size() == 1u);
      REQUIRE(ranges[0u].min == 0u);
      REQUIRE(ranges[0u].max == 0u);
    }
    {
      write<Range<unsigned int>, vector>("res/test/h.dat", vector{ Range{ 1u, 2u } });
      const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/h.dat") };
      REQUIRE(ranges.size() == 1u);
      REQUIRE(ranges[0u].min == 1u);
      REQUIRE(ranges[0u].max == 2u);
    }
    {
      write<Range<unsigned int>, vector>("res/test/i.dat", vector{ Range{ 1u, 2u }, Range{ 3u, 3u } });
      const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/i.dat") };
      REQUIRE(ranges.size() == 2u);
      REQUIRE(ranges[0u].min == 1u);
      REQUIRE(ranges[0u].max == 2u);
      REQUIRE(ranges[1u].min == 3u);
      REQUIRE(ranges[1u].max == 3u);
    }
    {
      write<Range<unsigned int>, vector>("res/test/j.dat", vector{ Range{ 1u, 2u }, Range{ 4u, 5u } });
      const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/j.dat") };
      REQUIRE(ranges.size() == 2u);
      REQUIRE(ranges[0u].min == 1u);
      REQUIRE(ranges[0u].max == 2u);
      REQUIRE(ranges[1u].min == 4u);
      REQUIRE(ranges[1u].max == 5u);
    }
  }
  SECTION("test hasFileWithExtension() function") {
    REQUIRE_FALSE(hasFileWithExtension("res/test/a/", ".txt"));
    REQUIRE(hasFileWithExtension("res/test/c/", ".txt"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/d/", ".txt"));
    REQUIRE(hasFileWithExtension("res/test/e/", ".txt"));
    REQUIRE(hasFileWithExtension("res/test/f/", ".txt"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/g/", ".txt"));
    REQUIRE(hasFileWithExtension("res/test/h/", ".txt"));
    REQUIRE(hasFileWithExtension("res/test/i/", ".txt"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/a/", ".png"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/c/", ".png"));
    REQUIRE(hasFileWithExtension("res/test/d/", ".png"));
    REQUIRE(hasFileWithExtension("res/test/e/", ".png"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/f/", ".png"));
    REQUIRE(hasFileWithExtension("res/test/g/", ".png"));
    REQUIRE(hasFileWithExtension("res/test/h/", ".png"));
    REQUIRE_FALSE(hasFileWithExtension("res/test/i/", ".png"));
  }
  remove_all("res/test/a/");
}

}  // namespace ii887522::nitro

#endif
