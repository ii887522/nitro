#ifdef TEST

#include "AnimatedAny.test.h"
#include <cassert>
#include "../../main/Any/AnimatedAny.h"
#include "../../main/Any/Reactive.h"
#include <stdexcept>

using std::runtime_error;

namespace ii887522::nitro
{
	static void testBuild()
	{
		assert(AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build().get() == 0);
		assert(AnimatedAny<int>::Builder{ 1 }.setDuration(250u).build().get() == 1);
		assert(AnimatedAny<int>::Builder{ 1 }.setDuration(500u).build().get() == 1);
		{
			auto n{ 0u };
			assert((AnimatedAny<int>::Builder{ 1, [&n]() {
				++n;
			} }.setDuration(500u).build().get() == 1));
			assert(n == 0u);
		}
		try
		{
			AnimatedAny<int>::Builder{ 0 }.build();
		}
		catch (const runtime_error&)
		{
			try
			{
				AnimatedAny<int>::Builder{ 1 }.build();
			}
			catch (const runtime_error&)
			{
				try
				{
					auto n{ 0u };
					AnimatedAny<int>::Builder{ 1, [&n]() {
						++n;
					} }.build();
				}
				catch (const runtime_error&)
				{
					return;
				}
			}
		}
		assert(false);
	}

	static void testTeleport()
	{
		{
			AnimatedAny n{ AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build() };
			n.teleport(1);
			assert(n.getStart() == 0);
			assert(n.get() == 1);
			assert(n.getEnd() == 1);
			n.teleport(2);
			assert(n.getStart() == 1);
			assert(n.get() == 2);
			assert(n.getEnd() == 2);
		}
		{
			AnimatedAny n{ AnimatedAny<int>::Builder{ 10 }.setDuration(250u).build() };
			n.teleport(1);
			assert(n.getStart() == 10);
			assert(n.get() == 1);
			assert(n.getEnd() == 1);
			n.teleport(2);
			assert(n.getStart() == 1);
			assert(n.get() == 2);
			assert(n.getEnd() == 2);
		}
		{
			AnimatedAny n{ AnimatedAny<int>::Builder{ 10 }.setDuration(500u).build() };
			n.teleport(1);
			assert(n.getStart() == 10);
			assert(n.get() == 1);
			assert(n.getEnd() == 1);
			n.teleport(2);
			assert(n.getStart() == 1);
			assert(n.get() == 2);
			assert(n.getEnd() == 2);
		}
		{
			auto m{ 0u };
			AnimatedAny n{ AnimatedAny<int>::Builder{ 10, [&m]() {
				++m;
			} }.setDuration(500u).build() };
			n.teleport(1);
			assert(n.getStart() == 10);
			assert(n.get() == 1);
			assert(n.getEnd() == 1);
			assert(m == 0u);
			n.teleport(2);
			assert(n.getStart() == 1);
			assert(n.get() == 2);
			assert(n.getEnd() == 2);
			assert(m == 0u);
		}
	}

	static void testStep()
	{
		{
			AnimatedAny n{ AnimatedAny<int>::Builder{ 0 }.setDuration(250u).build() };
			n.set(100);
			n.step(0u);
			assert(n.getStart() == 0);
			assert(n.get() == 0);
			assert(n.getEnd() == 100);
			n.step(30u);
			assert(n.getStart() == 0);
			assert(n.get() == 12);
			assert(n.getEnd() == 100);
			n.step(40u);
			assert(n.getStart() == 0);
			assert(n.get() == 28);
			assert(n.getEnd() == 100);
			n.step(50u);
			assert(n.getStart() == 0);
			assert(n.get() == 48);
			assert(n.getEnd() == 100);
			n.step(60u);
			assert(n.getStart() == 0);
			assert(n.get() == 72);
			assert(n.getEnd() == 100);
			n.step(70u);
			assert(n.getStart() == 0);
			assert(n.get() == 100);
			assert(n.getEnd() == 100);
		}
		{
			AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10 }.setDuration(250u).build() };
			n.set(110);
			n.step(0u);
			assert(n.getStart() == 10);
			assert(n.get() == 10);
			assert(n.getEnd() == 110);
			n.step(30u);
			assert(n.getStart() == 10);
			assert(n.get() == 22);
			assert(n.getEnd() == 110);
			n.step(40u);
			assert(n.getStart() == 10);
			assert(n.get() == 38);
			assert(n.getEnd() == 110);
			n.step(50u);
			assert(n.getStart() == 10);
			assert(n.get() == 58);
			assert(n.getEnd() == 110);
			n.step(60u);
			assert(n.getStart() == 10);
			assert(n.get() == 82);
			assert(n.getEnd() == 110);
			n.step(70u);
			assert(n.getStart() == 10);
			assert(n.get() == 110);
			assert(n.getEnd() == 110);
		}
		{
			AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10 }.setDuration(500u).build() };
			n.set(110);
			n.step(0u);
			assert(n.getStart() == 10);
			assert(n.get() == 10);
			assert(n.getEnd() == 110);
			n.step(60u);
			assert(n.getStart() == 10);
			assert(n.get() == 22);
			assert(n.getEnd() == 110);
			n.step(80u);
			assert(n.getStart() == 10);
			assert(n.get() == 38);
			assert(n.getEnd() == 110);
			n.step(100u);
			assert(n.getStart() == 10);
			assert(n.get() == 58);
			assert(n.getEnd() == 110);
			n.step(120u);
			assert(n.getStart() == 10);
			assert(n.get() == 82);
			assert(n.getEnd() == 110);
			n.step(140u);
			assert(n.getStart() == 10);
			assert(n.get() == 110);
			assert(n.getEnd() == 110);
		}
		{
			auto m{ 0u };
			AnimatedAny n{ AnimatedAny<unsigned int>::Builder{ 10, [&m]() {
				++m;
			} }.setDuration(500u).build() };
			n.set(110);
			n.step(0u);
			assert(n.getStart() == 10);
			assert(n.get() == 10);
			assert(n.getEnd() == 110);
			assert(m == 0u);
			n.step(60u);
			assert(n.getStart() == 10);
			assert(n.get() == 22);
			assert(n.getEnd() == 110);
			assert(m == 0u);
			n.step(80u);
			assert(n.getStart() == 10);
			assert(n.get() == 38);
			assert(n.getEnd() == 110);
			assert(m == 0u);
			n.step(100u);
			assert(n.getStart() == 10);
			assert(n.get() == 58);
			assert(n.getEnd() == 110);
			assert(m == 0u);
			n.step(120u);
			assert(n.getStart() == 10);
			assert(n.get() == 82);
			assert(n.getEnd() == 110);
			assert(m == 0u);
			n.step(140u);
			assert(n.getStart() == 10);
			assert(n.get() == 110);
			assert(n.getEnd() == 110);
			assert(m == 1u);
			n.step(10u);
			assert(n.getStart() == 10);
			assert(n.get() == 110);
			assert(n.getEnd() == 110);
			assert(m == 1u);
		}
	}

	void testAnimatedAny()
	{
		testBuild();
		testTeleport();
		testStep();
	}
}

#endif
