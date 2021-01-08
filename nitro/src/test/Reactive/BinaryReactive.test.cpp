#ifdef TEST

#include "BinaryReactive.test.h"
#include "../../main/Reactive/BinaryReactive.h"
#include <cassert>
#include <cmath>

namespace ii887522::nitro
{
	static void testSet()
	{
		{
			BinaryReactive<unsigned int, unsigned int, unsigned int> m{ 0u };
			m.set(1u);
			assert(m.get() == 1u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> n{ 1u };
			n.set(2u);
			assert(n.get() == 2u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> p{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return *left + *right;
				}
			};
			m.set(2u);
			assert(m.get() == 2u);
			assert(p.get() == 4u);
			n.set(3u);
			assert(n.get() == 3u);
			assert(p.get() == 5u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> q{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return *left * *right;
				}
			};
			m.set(3u);
			assert(m.get() == 3u);
			assert(p.get() == 6u);
			assert(q.get() == 9u);
			n.set(4u);
			assert(n.get() == 4u);
			assert(p.get() == 7u);
			assert(q.get() == 12u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> r{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return static_cast<unsigned int>(pow(*left, *right));
				}
			};
			m.set(4u);
			assert(m.get() == 4u);
			assert(p.get() == 8u);
			assert(q.get() == 16u);
			assert(r.get() == 256u);
			n.set(5u);
			assert(n.get() == 5u);
			assert(p.get() == 9u);
			assert(q.get() == 20u);
			assert(r.get() == 625u);

			BinaryReactive<unsigned int, unsigned int, unsigned int> s{
				&m, nullptr, [](const unsigned int*const left, const unsigned int*const) {
					return *left;
				}
			};
			m.set(5u);
			assert(m.get() == 5u);
			assert(p.get() == 10u);
			assert(q.get() == 25u);
			assert(r.get() == 3125u);
			assert(s.get() == 5u);
			n.set(6u);
			assert(n.get() == 6u);
			assert(p.get() == 11u);
			assert(q.get() == 30u);
			assert(r.get() == 7776u);
			assert(s.get() == 5u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> t{
				nullptr, &n, [](const unsigned int*const, const unsigned int*const) {
					return 0u;
				}
			};
			m.set(6u);
			assert(m.get() == 6u);
			assert(p.get() == 12u);
			assert(q.get() == 36u);
			assert(r.get() == 46656u);
			assert(s.get() == 6u);
			assert(t.get() == 0u);
			n.set(7u);
			assert(n.get() == 7u);
			assert(p.get() == 13u);
			assert(q.get() == 42u);
			assert(r.get() == 117649u);
			assert(s.get() == 6u);
			assert(t.get() == 0u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> u{
				nullptr, nullptr, [](const unsigned int*const, const unsigned int*const) {
					return 1u;
				}
			};
		}
		{
			BinaryReactive<unsigned int, unsigned int, unsigned int> m{ 2u };
			m.set(1u);
			assert(m.get() == 1u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> n{ 3u };
			n.set(2u);
			assert(n.get() == 2u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> p{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return *left + *right;
				}
			};
			m.set(2u);
			assert(m.get() == 2u);
			assert(p.get() == 4u);
			n.set(3u);
			assert(n.get() == 3u);
			assert(p.get() == 5u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> q{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return *left * *right;
				}
			};
			m.set(3u);
			assert(m.get() == 3u);
			assert(p.get() == 6u);
			assert(q.get() == 9u);
			n.set(4u);
			assert(n.get() == 4u);
			assert(p.get() == 7u);
			assert(q.get() == 12u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> r{
				&m, &n, [](const unsigned int*const left, const unsigned int*const right) {
					return static_cast<unsigned int>(pow(*left, *right));
				}
			};
			m.set(4u);
			assert(m.get() == 4u);
			assert(p.get() == 8u);
			assert(q.get() == 16u);
			assert(r.get() == 256u);
			n.set(5u);
			assert(n.get() == 5u);
			assert(p.get() == 9u);
			assert(q.get() == 20u);
			assert(r.get() == 625u);

			BinaryReactive<unsigned int, unsigned int, unsigned int> s{
				&m, nullptr, [](const unsigned int*const left, const unsigned int*const) {
					return *left;
				}
			};
			m.set(5u);
			assert(m.get() == 5u);
			assert(p.get() == 10u);
			assert(q.get() == 25u);
			assert(r.get() == 3125u);
			assert(s.get() == 5u);
			n.set(6u);
			assert(n.get() == 6u);
			assert(p.get() == 11u);
			assert(q.get() == 30u);
			assert(r.get() == 7776u);
			assert(s.get() == 5u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> t{
				nullptr, &n, [](const unsigned int*const, const unsigned int*const) {
					return 0u;
				}
			};
			m.set(6u);
			assert(m.get() == 6u);
			assert(p.get() == 12u);
			assert(q.get() == 36u);
			assert(r.get() == 46656u);
			assert(s.get() == 6u);
			assert(t.get() == 0u);
			n.set(7u);
			assert(n.get() == 7u);
			assert(p.get() == 13u);
			assert(q.get() == 42u);
			assert(r.get() == 117649u);
			assert(s.get() == 6u);
			assert(t.get() == 0u);
			BinaryReactive<unsigned int, unsigned int, unsigned int> u{
				nullptr, nullptr, [](const unsigned int* const, const unsigned int* const) {
					return 1u;
				}
			};
		}
	}

	void testBinaryReactive()
	{
		testSet();
	}
}

#endif
