// Copyright ii887522

#ifdef TEST

#include "fs_ext.test.h"  // NOLINT(build/include_subdir)
#include <cassert>
#include <vector>
#include <fstream>
#include "../../main/Functions/fs_ext.h"
#include "../../main/Struct/Range.h"

using std::vector;
using std::ios;

namespace ii887522::nitro {

static void testRead() {
  try {
    read<char, vector>("a");
  } catch (const ios::failure&) {
    assert((read<char, vector>("res/test/a.dat").size() == 0u));
    {
      const vector<char> str{ read<char, vector>("res/test/b.dat") };
      assert(str.size() == 3u);
      assert(str[0u] == 'a');
      assert(str[1u] == '\r');
      assert(str[2u] == '\n');
    }
    {
      const vector<char> str{ read<char, vector>("res/test/c.dat") };
      assert(str.size() == 4u);
      assert(str[0u] == 'a');
      assert(str[1u] == 'b');
      assert(str[2u] == '\r');
      assert(str[3u] == '\n');
    }
    {
      const vector<unsigned int> ns{ read<unsigned int, vector>("res/test/d.dat") };
      assert(ns.size() == 1u);
      assert(ns[0u] == 56271439);
    }
    {
      const vector<unsigned int> ns{ read<unsigned int, vector>("res/test/e.dat") };
      assert(ns.size() == 2u);
      assert(ns[0u] == 56271439);
      assert(ns[1u] == 97025014);
    }
    return;
  }
  assert(false);
}

static void testWrite() {
  write<Range<unsigned int>, vector>("res/test/f.dat", vector<Range<unsigned int>>{ });
  assert((read<Range<unsigned int>, vector>("res/test/f.dat").size() == 0u));
  {
    write<Range<unsigned int>, vector>("res/test/g.dat", vector{ Range{ 0u, 0u } });
    const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/g.dat") };
    assert(ranges.size() == 1u);
    assert(ranges[0u].min == 0u);
    assert(ranges[0u].max == 0u);
  }
  {
    write<Range<unsigned int>, vector>("res/test/h.dat", vector{ Range{ 1u, 2u } });
    const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/h.dat") };
    assert(ranges.size() == 1u);
    assert(ranges[0u].min == 1u);
    assert(ranges[0u].max == 2u);
  }
  {
    write<Range<unsigned int>, vector>("res/test/i.dat", vector{ Range{ 1u, 2u }, Range{ 3u, 3u } });
    const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/i.dat") };
    assert(ranges.size() == 2u);
    assert(ranges[0u].min == 1u);
    assert(ranges[0u].max == 2u);
    assert(ranges[1u].min == 3u);
    assert(ranges[1u].max == 3u);
  }
  {
    write<Range<unsigned int>, vector>("res/test/j.dat", vector{ Range{ 1u, 2u }, Range{ 4u, 5u } });
    const vector<Range<unsigned int>> ranges{ read<Range<unsigned int>, vector>("res/test/j.dat") };
    assert(ranges.size() == 2u);
    assert(ranges[0u].min == 1u);
    assert(ranges[0u].max == 2u);
    assert(ranges[1u].min == 4u);
    assert(ranges[1u].max == 5u);
  }
}

void testFsExt() {
  testRead();
  testWrite();
}

}  // namespace ii887522::nitro

#endif
