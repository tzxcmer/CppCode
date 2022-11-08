#pragma once
#include "RBTree.h"

namespace tzx
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		s.insert(3);
		s.insert(2);
		s.insert(1);
		s.insert(5);
		s.insert(3);
		s.insert(6);
		s.insert(4);
		s.insert(9);
		s.insert(7);


		it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}