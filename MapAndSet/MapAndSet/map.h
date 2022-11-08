#pragma once
#include"RBTree.h"

namespace tzx
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

		map<string, int> countMap;
		for (auto& str : arr)
		{
			countMap[str]++;
		}

		map<string, int>::iterator it = countMap.begin();
		while (it != countMap.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
	
}
