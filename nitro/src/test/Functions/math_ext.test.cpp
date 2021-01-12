// Copyright ii887522

#ifdef TEST

#include "math_ext.test.h"  // NOLINT(build/include_subdir)
#include <cassert>
#include <algorithm>
#include "../../main/Functions/math_ext.h"
#include "../../main/Struct/Range.h"

namespace ii887522::nitro {

static void testClamp() {
  {
    auto n{ 0u };
    clamp(&n, Range{ 1u, 3u });
    assert(n == 1u);
  }
  {
    auto n{ 1u };
    clamp(&n, Range{ 1u, 3u });
    assert(n == 1u);
  }
  {
    auto n{ 2u };
    clamp(&n, Range{ 1u, 3u });
    assert(n == 2u);
  }
  {
    auto n{ 3u };
    clamp(&n, Range{ 1u, 3u });
    assert(n == 3u);
  }
  {
    auto n{ 4u };
    clamp(&n, Range{ 1u, 3u });
    assert(n == 3u);
  }
  {
    auto n{ 0u };
    clamp(&n, Range{ 2u, 6u });
    assert(n == 2u);
  }
  {
    auto n{ 2u };
    clamp(&n, Range{ 2u, 6u });
    assert(n == 2u);
  }
  {
    auto n{ 4u };
    clamp(&n, Range{ 2u, 6u });
    assert(n == 4u);
  }
  {
    auto n{ 6u };
    clamp(&n, Range{ 2u, 6u });
    assert(n == 6u);
  }
  {
    auto n{ 8u };
    clamp(&n, Range{ 2u, 6u });
    assert(n == 6u);
  }
}

constexpr static void testIsOverlapX() {
  static_assert(!isOverlapX(0u, Range{ 1u, 3u }));
  static_assert(isOverlapX(1u, Range{ 1u, 3u }));
  static_assert(isOverlapX(2u, Range{ 1u, 3u }));
  static_assert(!isOverlapX(3u, Range{ 1u, 3u }));
  static_assert(!isOverlapX(4u, Range{ 1u, 3u }));
  static_assert(!isOverlapX(0u, Range{ 2u, 6u }));
  static_assert(isOverlapX(2u, Range{ 2u, 6u }));
  static_assert(isOverlapX(4u, Range{ 2u, 6u }));
  static_assert(!isOverlapX(6u, Range{ 2u, 6u }));
  static_assert(!isOverlapX(8u, Range{ 2u, 6u }));
}

constexpr static void testIsOverlapY() {
  static_assert(!isOverlapY(0u, Range{ 1u, 3u }));
  static_assert(isOverlapY(1u, Range{ 1u, 3u }));
  static_assert(isOverlapY(2u, Range{ 1u, 3u }));
  static_assert(!isOverlapY(3u, Range{ 1u, 3u }));
  static_assert(!isOverlapY(4u, Range{ 1u, 3u }));
  static_assert(!isOverlapY(0u, Range{ 2u, 6u }));
  static_assert(isOverlapY(2u, Range{ 2u, 6u }));
  static_assert(isOverlapY(4u, Range{ 2u, 6u }));
  static_assert(!isOverlapY(6u, Range{ 2u, 6u }));
  static_assert(!isOverlapY(8u, Range{ 2u, 6u }));
}

constexpr static void testMin() {
  static_assert(min(0u, 0u) == 0u);
  static_assert(min(1u, 0u) == 0u);
  static_assert(min(1u, 1u) == 1u);
  static_assert(min(1u, 2u) == 1u);
}

constexpr static void testMax() {
  static_assert(max(0u, 0u) == 0u);
  static_assert(max(1u, 0u) == 1u);
  static_assert(max(1u, 1u) == 1u);
  static_assert(max(1u, 2u) == 2u);
}

void testMathExt() {
  testClamp();
  testIsOverlapX();
  testIsOverlapY();
  testMin();
  testMax();
}

}  // namespace ii887522::nitro

#endif
