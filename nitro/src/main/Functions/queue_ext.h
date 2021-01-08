#ifndef II887522_NITRO_QUEUE_EXT_H
#define II887522_NITRO_QUEUE_EXT_H

#include <queue>

using std::queue;

namespace ii887522::nitro
{
	template <typename T> void clear(queue<T>& queue)
	{
		while (!queue.empty()) queue.pop();
	}
}

#endif
