#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;


template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	// BKDR
	size_t operator()(const string& key)
	{
		size_t val = 0;
		for (auto ch : key)
		{
			val *= 131;
			val += ch;
		}

		return val;
	}
};

namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K,class V>
	struct hashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct hashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct hashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto ch : key)
			{
				val *= 131;
				val += ch;
			}

			return val;
		}
	};

	template<class K,class V,class Hash=hashFunc<K>>
	class hashTable
	{
	public:
		bool Insert(const pair<K,V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			if (_tables.size() == 0 || 10 * _size / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				hashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);

				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}

				_tables.swap(newHT._tables);
			}
			//线性探测
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size();

			
			while (_tables[hashi]._state == EXIST)
			{
				hashi++;
				hashi %= _tables.size();
			}

			
			////二次探测
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t i = 0;
			//size_t hashi = start;

			//while (_tables[hashi]._state == EXIST)
			//{
			//	i++;
			//	hashi = start + i * i;
			//	hashi %= _tables.size();
			//}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;

			return true;
		}

		hashData<K, V>* Find(const K& key)
		{
			if (_size == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t start = hash(key) % _tables.size();
			size_t hashi = start;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				hashi++;
				hashi %= _tables.size();

				if (hashi == start)
					break;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			hashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;

				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i]._state == EXIST)
				{
					//printf("[%d:%d] ", i, _tables[i]._kv.first);
					cout << "[" << _tables[i]._kv.first <<":" << _tables[i]._kv.second << "]";
				}
				else
				{
					//printf("[%d:*] ", i);
					cout << "[" << i << ":*]";
				}
			}
			std::cout << std::endl;
		}


	private:
		vector<hashData<K, V>> _tables;
		size_t _size = 0;
	};

}

namespace hashBucekt
{
	template<class T>
	struct hashNode
	{
		T _data;
		hashNode<T>* _next;

		hashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class Hash, class KeyOfT>
	class hashTable;


	template<class K, class T, class Hash, class KeyOfT>
	struct __hashIterator
	{
		typedef hashNode<T> Node;
		typedef hashTable<K, T, Hash, KeyOfT> HT;
		typedef __hashIterator<K, T, Hash, KeyOfT> Self;


		Node* _node;
		HT* _pht;

		__hashIterator(Node* node,HT* pht)
			:_node(node)
			,_pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				Hash hash;
				KeyOfT kot;

				size_t i = hash(kot(_node->_data)) % _pht->_tables.size();
				++i;

				for (;i < _pht->_tables.size();i++)
				{
					if (_pht->_tables[i])
					{
						_node = _pht->_tables[i];
						break;
					}

					if (i == _pht->_tables.size())
					{
						return nullptr;
					}
				}
			}

			return *this;
		}

		bool operator!=(Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(Self& s)const
		{
			return _node == s._node;
		}
	};


	template<class K, class T, class Hash, class KeyOfT>
	class hashTable
	{
		typedef hashNode<T> Node;

		template<class K, class T, class Hash, class KeyOfT>
		friend struct __hashIterator;
	public:
		typedef __hashIterator<K, T, Hash, KeyOfT> iterator;


		iterator begin()
		{
			for (size_t i = 0;i < _tables.size();i++)
			{
				if (_tables[i])
				{
					return itreator(_tables[i], this);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		~hashTable()
		{
			for (size_t i = 0;i < _tables.size();i++)
			{
				Node* cur = _tables[i];

				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_tables[i] = nullptr;
			}
		}

		inline size_t __stl_next_prime(size_t n)
		{
			static const size_t __stl_num_primes = 28;
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (size_t i = 0;i < __stl_num_primes;i++)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}


		pair<iterator,bool> Insert(const T& data)
		{
			Hash hash;
			KeyOfT kot;
			
			//去重
			iterator ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret,false);
			}

			if (_size == _tables.size())
			{
				//size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				//newTables.resize(newSize,nullptr);
				newTables.resize(__stl_next_prime(_tables.size()), nullptr);

				for (size_t i = 0;i < _tables.size();i++)
				{
					Node* cur = _tables[i];

					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hash(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = hash(kot(data)) & _tables.size();
			Node* newNode = new Node(data);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;
			++_size;

			return make_pair(iterator(newNode,this),true);
		}

		Node* Find(const K& key)
		{
			Hash hash;
			KeyOfT kot;

			if (_tables.size() == 0)
			{
				return nullptr;
			}
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur,this);
				}
				
				cur = cur->_next;
			}

			return end();
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			KeyOfT kot;

			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					//头删和中间删
					if (prev == nullptr)
					{
						_tables[i] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_size;

					return true;

				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		size_t Size()
		{
			return _size;
		}

		// 表的长度
		size_t TablesSize()
		{
			return _tables.size();
		}

		//桶的个数
		size_t BucketNum()
		{
			size_t num = 0;

			for (size_t i = 0;i < _tables.size();i++)
			{
				if (_tables[i])
				{
					++num;
				}
			}

			return num;
		}

		size_t MaxBucketLenth()
		{
			size_t maxLen = 0;
			
			for (size_t i = 0;i < _tables.size();i++)
			{
				Node* cur = _tables[i];
				size_t len = 0;

				while (cur)
				{
					++len;
					cur = cur->_next;
				}

				if (len > maxLen)
				{
					maxLen = len;
				}
			}

			return maxLen;
		}

	private:
		vecotr<Node*> _tables;
		size_t size = 0;
	};
}
