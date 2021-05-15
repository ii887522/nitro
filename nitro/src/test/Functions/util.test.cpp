// Copyright ii887522

#ifdef TEST

#include "util.test.h"  // NOLINT(build/include_subdir)
#include <cassert>
#include <vector>
#include "../../main/Struct/Range.h"
#include "../../main/Functions/util.h"

using std::vector;

namespace ii887522::nitro {

static void testSwap() {
  {
    auto p{ 0u };
    auto q{ 0u };
    swap(p, q);
    assert(p == 0u);
    assert(q == 0u);
  }
  {
    auto p{ 1u };
    auto q{ 0u };
    swap(p, q);
    assert(p == 0u);
    assert(q == 1u);
  }
  {
    auto p{ 2u };
    auto q{ 0u };
    swap(p, q);
    assert(p == 0u);
    assert(q == 2u);
  }
  {
    auto p{ 2u };
    auto q{ 1u };
    swap(p, q);
    assert(p == 1u);
    assert(q == 2u);
  }
  {
    auto p{ 2u };
    auto q{ 2u };
    swap(p, q);  // NOLINT(build/include_what_you_use)
    assert(p == 2u);
    assert(q == 2u);
  }
}

static void testInsertionSort() {
  {
    vector<unsigned int> ns{ 0u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSort<unsigned int, vector>(&ns, Range{ 0u, static_cast<unsigned int>(ns.size() - 1u) }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 5u };
    insertionSort<unsigned int, vector>(&ns, Range{ 1u, static_cast<unsigned int>(ns.size() - 1u) }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 5u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 2u);
    assert(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 5u };
    insertionSort<unsigned int, vector>(&ns, Range{ 1u, 3u }, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
    assert(ns[4u] == 5u);
  }
}

static void testMergeSort() {
  {
    vector<unsigned int> ns{ 0u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    mergeSort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 4u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 2u);
    assert(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 4u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 2u);
    assert(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 1u);
    assert(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 5u);
    assert(ns[3u] == 4u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 2u);
    assert(ns[7u] == 1u);
    assert(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 6u);
    assert(ns[3u] == 5u);
    assert(ns[4u] == 4u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 2u);
    assert(ns[8u] == 1u);
    assert(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    mergeSort<unsigned int, vector>(&ns, 2u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 7u);
    assert(ns[3u] == 6u);
    assert(ns[4u] == 5u);
    assert(ns[5u] == 4u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 3u);
    assert(ns[8u] == 2u);
    assert(ns[9u] == 1u);
    assert(ns[10u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    mergeSort<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 7);
    assert(ns[1u] == 6);
    assert(ns[2u] == 5);
    assert(ns[3u] == 9);
    assert(ns[4u] == 4);
    assert(ns[5u] == 8);
    assert(ns[6u] == 3);
    assert(ns[7u] == 3);
    assert(ns[8u] == 2);
    assert(ns[9u] == 1);
    assert(ns[10u] == 0);
  }
}

static void testInsertionSorts() {
  {
    vector<unsigned int> ns{ 0u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSorts<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    insertionSorts<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    insertionSorts<unsigned int, vector>(&ns, 5u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 4u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 2u);
    assert(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    insertionSorts<unsigned int, vector>(&ns, 6u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 4u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 2u);
    assert(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    insertionSorts<unsigned int, vector>(&ns, 7u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    insertionSorts<unsigned int, vector>(&ns, 8u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 1u);
    assert(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    insertionSorts<unsigned int, vector>(&ns, 9u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 5u);
    assert(ns[3u] == 4u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 2u);
    assert(ns[7u] == 1u);
    assert(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    insertionSorts<unsigned int, vector>(&ns, 10u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 6u);
    assert(ns[3u] == 5u);
    assert(ns[4u] == 4u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 2u);
    assert(ns[8u] == 1u);
    assert(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    insertionSorts<unsigned int, vector>(&ns, 11u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 7u);
    assert(ns[3u] == 6u);
    assert(ns[4u] == 5u);
    assert(ns[5u] == 4u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 3u);
    assert(ns[8u] == 2u);
    assert(ns[9u] == 1u);
    assert(ns[10u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    insertionSorts<unsigned int, vector>(&ns, 4u, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
    assert(ns[4u] == 8u);
    assert(ns[5u] == 6u);
    assert(ns[6u] == 4u);
    assert(ns[7u] == 1u);
    assert(ns[8u] == 9u);
    assert(ns[9u] == 7u);
    assert(ns[10u] == 5u);
  }
}

static void testSort() {
  {
    vector<unsigned int> ns{ 0u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
  }
  {
    vector<unsigned int> ns{ 1u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 0u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 1u, 1u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 0u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 1u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 1u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 2u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 2u);
  }
  {
    vector<unsigned int> ns{ 2u, 1u, 3u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 1u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 2u, 2u, 3u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 2u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    sort<unsigned int, vector>(&ns);
    assert(ns[0u] == 0u);
    assert(ns[1u] == 2u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 3u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 2u);
    assert(ns[3u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 4u);
    assert(ns[1u] == 3u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 2u);
    assert(ns[4u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 4u);
    assert(ns[2u] == 3u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 2u);
    assert(ns[5u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 4u);
    assert(ns[3u] == 3u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 2u);
    assert(ns[6u] == 1u);
    assert(ns[7u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 8u);
    assert(ns[1u] == 6u);
    assert(ns[2u] == 5u);
    assert(ns[3u] == 4u);
    assert(ns[4u] == 3u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 2u);
    assert(ns[7u] == 1u);
    assert(ns[8u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 6u);
    assert(ns[3u] == 5u);
    assert(ns[4u] == 4u);
    assert(ns[5u] == 3u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 2u);
    assert(ns[8u] == 1u);
    assert(ns[9u] == 0u);
  }
  {
    vector<unsigned int> ns{ 3u, 2u, 3u, 0u, 4u, 8u, 6u, 1u, 5u, 9u, 7u };
    sort<unsigned int, vector>(&ns, [](const unsigned int& l, const unsigned int& r) {  // NOLINT(build/include_what_you_use)
      return l < r;
    });
    assert(ns[0u] == 9u);
    assert(ns[1u] == 8u);
    assert(ns[2u] == 7u);
    assert(ns[3u] == 6u);
    assert(ns[4u] == 5u);
    assert(ns[5u] == 4u);
    assert(ns[6u] == 3u);
    assert(ns[7u] == 3u);
    assert(ns[8u] == 2u);
    assert(ns[9u] == 1u);
    assert(ns[10u] == 0u);
  }
}

void testUtil() {
  testSwap();
  testInsertionSort();
  testMergeSort();
  testInsertionSorts();
  testSort();
}

}  // namespace ii887522::nitro

#endif
