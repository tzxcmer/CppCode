#pragma once
#include"hashtable.h"

namespace tzx
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename hashBucket::HashTable<K, K, Hash, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}
	private:
		hashBucket::HashTable<K, K, Hash, SetKeyOfT> _ht;
	};
}