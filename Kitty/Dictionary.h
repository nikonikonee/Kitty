#pragma once
#include <map>
#include <vector>
#include "Array.h"

namespace SDK::Structs::Mono
{
	template <typename TKey, typename TValue>
	struct Dictionary
	{
		struct Entry
		{
			int hashCode;
			int next;
			TKey key;
			TValue value;
		};

		void* klass;
		void* monitor;

		Array<int>* _buckets;
		Array<Entry>* _entries;
		int count;
		int freeList;
		int freeCount;
		int version;
		void* comparer;
		Array<TKey>* keys;
		Array<TValue>* values{};
		void* syncRoot{};

		Entry get_Entry(int index) {
			return reinterpret_cast<Entry*>(_entries->vector)[index];
		}
	};
}