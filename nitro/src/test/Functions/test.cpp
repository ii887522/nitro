// Copyright ii887522

#ifdef TEST

#define ALLOCATOR_IMPLEMENTATIONS
#include "../../main/Any/allocator.h"

#include "../Struct/Vector.test.h"
#include "../Functions/math_ext.test.h"
#include "../Any/AnimatedAny.test.h"
#include "../Any/Reactive.test.h"
#include "../Functions/queue_ext.test.h"
#include "../Reactive/UnaryReactive.test.h"
#include "../Reactive/BinaryReactive.test.h"
#include "../Functions/fs_ext.test.h"
#include "../Functions/string_ext.test.h"
#include "../Functions/util.test.h"

namespace ii887522::nitro {

static int main() {
  testVector();
  testMathExt();
  testAnimatedAny();
  testReactive();
  testQueueExt();
  testUnaryReactive();
  testBinaryReactive();
  testFsExt();
  testStringExt();
  testUtil();
  return EXIT_SUCCESS;
}

}  // namespace ii887522::nitro

int main() {
  return ii887522::nitro::main();
}

#endif
