// Copyright ii887522

#ifdef TEST

#include <vector>
#include <catch.hpp>
#include "../../main/Struct/Range.h"
#include "../../main/Functions/util.h"

using std::vector;

namespace ii887522::nitro {

TEST_CASE("test swap() function") {
  {
    auto p{ 0u };
    auto q{ 0u };
    swap(p, q);
    REQUIRE(p == 0u);
    REQUIRE(q == 0u);
  }
  {
    auto p{ 1u };
    auto q{ 0u };
    swap(p, q);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
  }
  {
    auto p{ 2u };
    auto q{ 0u };
    swap(p, q);
    REQUIRE(p == 0u);
    REQUIRE(q == 2u);
  }
  {
    auto p{ 2u };
    auto q{ 1u };
    swap(p, q);
    REQUIRE(p == 1u);
    REQUIRE(q == 2u);
  }
  {
    auto p{ 2u };
    auto q{ 2u };
    swap(p, q);  // NOLINT(build/include_what_you_use)
    REQUIRE(p == 2u);
    REQUIRE(q == 2u);
  }
}

TEST_CASE("test insertionSort() function") {
  {
    vector<unsigned int> ns{ 0u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSort<unsigned int, vector>(&ns, Range{ 0u, static_cast<unsigned int>(ns.size() - 1u) }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
      });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 5u };
    insertionSort<unsigned int, vector>(&ns, Range{ 1u, static_cast<unsigned int>(ns.size() - 1u) }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
      });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 5u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 2u);
    REQUIRE(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 5u };
    insertionSort<unsigned int, vector>(&ns, Range{ 1u, 3u }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
      });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
    REQUIRE(ns[4u] == 5u);
  }
}

TEST_CASE("test mergeSort() function") {
  {
    vector<unsigned int> ns{ 0u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 4u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 2u);
    REQUIRE(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 4u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 2u);
    REQUIRE(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 1u);
    REQUIRE(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 5u);
    REQUIRE(ns[3u] == 4u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 2u);
    REQUIRE(ns[7u] == 1u);
    REQUIRE(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 6u);
    REQUIRE(ns[3u] == 5u);
    REQUIRE(ns[4u] == 4u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 2u);
    REQUIRE(ns[8u] == 1u);
    REQUIRE(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 7u);
    REQUIRE(ns[3u] == 6u);
    REQUIRE(ns[4u] == 5u);
    REQUIRE(ns[5u] == 4u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 3u);
    REQUIRE(ns[8u] == 2u);
    REQUIRE(ns[9u] == 1u);
    REQUIRE(ns[10u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    mergeSort<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 7);
    REQUIRE(ns[1u] == 6);
    REQUIRE(ns[2u] == 5);
    REQUIRE(ns[3u] == 9);
    REQUIRE(ns[4u] == 4);
    REQUIRE(ns[5u] == 8);
    REQUIRE(ns[6u] == 3);
    REQUIRE(ns[7u] == 3);
    REQUIRE(ns[8u] == 2);
    REQUIRE(ns[9u] == 1);
    REQUIRE(ns[10u] == 0);
  }
}

TEST_CASE("test insertionSorts() function") {
  {
    vector<unsigned int> ns{ 0u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSorts<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    insertionSorts<unsigned int, vector>(&ns, 5u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 4u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 2u);
    REQUIRE(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    insertionSorts<unsigned int, vector>(&ns, 6u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 4u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 2u);
    REQUIRE(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    insertionSorts<unsigned int, vector>(&ns, 7u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    insertionSorts<unsigned int, vector>(&ns, 8u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 1u);
    REQUIRE(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    insertionSorts<unsigned int, vector>(&ns, 9u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 5u);
    REQUIRE(ns[3u] == 4u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 2u);
    REQUIRE(ns[7u] == 1u);
    REQUIRE(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    insertionSorts<unsigned int, vector>(&ns, 10u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 6u);
    REQUIRE(ns[3u] == 5u);
    REQUIRE(ns[4u] == 4u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 2u);
    REQUIRE(ns[8u] == 1u);
    REQUIRE(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    insertionSorts<unsigned int, vector>(&ns, 11u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 7u);
    REQUIRE(ns[3u] == 6u);
    REQUIRE(ns[4u] == 5u);
    REQUIRE(ns[5u] == 4u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 3u);
    REQUIRE(ns[8u] == 2u);
    REQUIRE(ns[9u] == 1u);
    REQUIRE(ns[10u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    insertionSorts<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
    REQUIRE(ns[4u] == 8u);
    REQUIRE(ns[5u] == 6u);
    REQUIRE(ns[6u] == 4u);
    REQUIRE(ns[7u] == 1u);
    REQUIRE(ns[8u] == 9u);
    REQUIRE(ns[9u] == 7u);
    REQUIRE(ns[10u] == 5u);
  }
}

TEST_CASE("test sort() function") {
  {
    vector<unsigned int> ns{ 0u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 1u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 1u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 2u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    sort<unsigned int, vector>(&ns);
    REQUIRE(ns[0u] == 0u);
    REQUIRE(ns[1u] == 2u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 3u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 2u);
    REQUIRE(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 4u);
    REQUIRE(ns[1u] == 3u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 2u);
    REQUIRE(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 4u);
    REQUIRE(ns[2u] == 3u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 2u);
    REQUIRE(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 4u);
    REQUIRE(ns[3u] == 3u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 2u);
    REQUIRE(ns[6u] == 1u);
    REQUIRE(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 8u);
    REQUIRE(ns[1u] == 6u);
    REQUIRE(ns[2u] == 5u);
    REQUIRE(ns[3u] == 4u);
    REQUIRE(ns[4u] == 3u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 2u);
    REQUIRE(ns[7u] == 1u);
    REQUIRE(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 6u);
    REQUIRE(ns[3u] == 5u);
    REQUIRE(ns[4u] == 4u);
    REQUIRE(ns[5u] == 3u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 2u);
    REQUIRE(ns[8u] == 1u);
    REQUIRE(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {  // NOLINT(build/include_what_you_use)
      return l < r;
    });
    REQUIRE(ns[0u] == 9u);
    REQUIRE(ns[1u] == 8u);
    REQUIRE(ns[2u] == 7u);
    REQUIRE(ns[3u] == 6u);
    REQUIRE(ns[4u] == 5u);
    REQUIRE(ns[5u] == 4u);
    REQUIRE(ns[6u] == 3u);
    REQUIRE(ns[7u] == 3u);
    REQUIRE(ns[8u] == 2u);
    REQUIRE(ns[9u] == 1u);
    REQUIRE(ns[10u] == 0u);
  }
}

}  // namespace ii887522::nitro

#endif
