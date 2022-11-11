#pragma once
#include"hashtable.h"

namespace tzx
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename hashBucket::HashTable<K, pair<K, V>, Hash, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			_ht.begin();
		}

		iterator end()
		{
			_ht.end();
		}

		pair<iterator, bool> Insert(const pair<K,V>& kv)
		{
			_ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		hashBucket::HashTable<K, pair<K, V>, Hash, MapKeyOfT> _ht;
	};
}
