// Copyright ii887522

#ifdef TEST

#include "../Struct/Vector.test.h"
#include "../Functions/math_ext.test.h"
#include "../Any/AnimatedAny.test.h"
#include "../Any/Reactive.test.h"
#include "../Functions/queue_ext.test.h"
#include "../Reactive/UnaryReactive.test.h"
#include "../Reactive/BinaryReactive.test.h"

namespace ii887522::nitro {

static int main() {
  testVector();
  testMathExt();
  testAnimatedAny();
  testReactive();
  testQueueExt();
  testUnaryReactive();
  testBinaryReactive();
  return 0;
}

}  // namespace ii887522::nitro

int main() {
  return ii887522::nitro::main();
}

#endif
