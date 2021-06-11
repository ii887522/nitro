// Copyright ii887522

#ifdef TEST

#include <algorithm>
#include <catch.hpp>
#include "../../main/Functions/math_ext.h"
#include "../../main/Struct/Range.h"

namespace ii887522::nitro {

TEST_CASE("test clamp() function") {
  {
    auto n{ 0u };
    clamp(&n, Range{ 1u, 3u });
    REQUIRE(n == 1u);
  }
  {
    auto n{ 1u };
    clamp(&n, Range{ 1u, 3u });
    REQUIRE(n == 1u);
  }
  {
    auto n{ 2u };
    clamp(&n, Range{ 1u, 3u });
    REQUIRE(n == 2u);
  }
  {
    auto n{ 3u };
    clamp(&n, Range{ 1u, 3u });
    REQUIRE(n == 3u);
  }
  {
    auto n{ 4u };
    clamp(&n, Range{ 1u, 3u });
    REQUIRE(n == 3u);
  }
  {
    auto n{ 0u };
    clamp(&n, Range{ 2u, 6u });
    REQUIRE(n == 2u);
  }
  {
    auto n{ 2u };
    clamp(&n, Range{ 2u, 6u });
    REQUIRE(n == 2u);
  }
  {
    auto n{ 4u };
    clamp(&n, Range{ 2u, 6u });
    REQUIRE(n == 4u);
  }
  {
    auto n{ 6u };
    clamp(&n, Range{ 2u, 6u });
    REQUIRE(n == 6u);
  }
  {
    auto n{ 8u };
    clamp(&n, Range{ 2u, 6u });
    REQUIRE(n == 6u);
  }
}

TEST_CASE("test isOverlapX() function") {
  REQUIRE_FALSE(isOverlapX(0u, Range{ 1u, 3u }));
  REQUIRE(isOverlapX(1u, Range{ 1u, 3u }));
  REQUIRE(isOverlapX(2u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapX(3u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapX(4u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapX(0u, Range{ 2u, 6u }));
  REQUIRE(isOverlapX(2u, Range{ 2u, 6u }));
  REQUIRE(isOverlapX(4u, Range{ 2u, 6u }));
  REQUIRE_FALSE(isOverlapX(6u, Range{ 2u, 6u }));
  REQUIRE_FALSE(isOverlapX(8u, Range{ 2u, 6u }));
}

TEST_CASE("test isOverlapY() function") {
  REQUIRE_FALSE(isOverlapY(0u, Range{ 1u, 3u }));
  REQUIRE(isOverlapY(1u, Range{ 1u, 3u }));
  REQUIRE(isOverlapY(2u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapY(3u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapY(4u, Range{ 1u, 3u }));
  REQUIRE_FALSE(isOverlapY(0u, Range{ 2u, 6u }));
  REQUIRE(isOverlapY(2u, Range{ 2u, 6u }));
  REQUIRE(isOverlapY(4u, Range{ 2u, 6u }));
  REQUIRE_FALSE(isOverlapY(6u, Range{ 2u, 6u }));
  REQUIRE_FALSE(isOverlapY(8u, Range{ 2u, 6u }));
}

TEST_CASE("test min() function") {
  REQUIRE(min(0u, 0u) == 0u);
  REQUIRE(min(1u, 0u) == 0u);
  REQUIRE(min(1u, 1u) == 1u);
  REQUIRE(min(1u, 2u) == 1u);
}

TEST_CASE("test max() function") {
  REQUIRE(max(0u, 0u) == 0u);
  REQUIRE(max(1u, 0u) == 1u);
  REQUIRE(max(1u, 1u) == 1u);
  REQUIRE(max(1u, 2u) == 2u);
}

TEST_CASE("test isDigit() function") {
  REQUIRE_FALSE(isDigit('/'));
  REQUIRE(isDigit('0'));
  REQUIRE(isDigit('5'));
  REQUIRE(isDigit('9'));
  REQUIRE_FALSE(isDigit(':'));
}

TEST_CASE("test isUint() function") {
  REQUIRE_FALSE(isUint("/"));
  REQUIRE(isUint("0"));
  REQUIRE(isUint("5"));
  REQUIRE(isUint("9"));
  REQUIRE_FALSE(isUint(":"));
  REQUIRE_FALSE(isUint(":/"));
  REQUIRE_FALSE(isUint(":0"));
  REQUIRE_FALSE(isUint(":9"));
  REQUIRE_FALSE(isUint("::"));
  REQUIRE_FALSE(isUint(":5"));
  REQUIRE_FALSE(isUint("9/"));
  REQUIRE(isUint("95"));
  REQUIRE_FALSE(isUint("95/"));
  REQUIRE(isUint("950"));
  REQUIRE(isUint("955"));
  REQUIRE(isUint("959"));
  REQUIRE_FALSE(isUint("95:"));
}

TEST_CASE("test parseUint(const char) function") {
  REQUIRE(parseUint('0') == 0u);
  REQUIRE(parseUint('1') == 1u);
  REQUIRE(parseUint('2') == 2u);
}

TEST_CASE("test parseUint(const string&) function") {
  REQUIRE(parseUint("0") == 0u);
  REQUIRE(parseUint("1") == 1u);
  REQUIRE(parseUint("2") == 2u);
  REQUIRE(parseUint("20") == 20u);
  REQUIRE(parseUint("21") == 21u);
  REQUIRE(parseUint("31") == 31u);
  REQUIRE(parseUint("310") == 310u);
  REQUIRE(parseUint("311") == 311u);
  REQUIRE(parseUint("321") == 321u);
  REQUIRE(parseUint("421") == 421u);
}

TEST_CASE("test isPowerOfTwo() function") {
  REQUIRE(isPowerOfTwo(1u));
  REQUIRE(isPowerOfTwo(2u));
  REQUIRE_FALSE(isPowerOfTwo(3u));
  REQUIRE(isPowerOfTwo(4u));
  REQUIRE_FALSE(isPowerOfTwo(5u));
}

}  // namespace ii887522::nitro

#endif
