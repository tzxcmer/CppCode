#define _CRT_SECURE_NO_WARNINGS 1
#include"hashtable.h"

void TestHT1()
{
	//int a[] = { 1, 11, 4, 15, 26, 7, 44, 9 };
	int a[] = { 1, 11, 4, 15, 26, 7, 44 };
	CloseHash::hashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	ht.Print();

	ht.Erase(4);
	cout << ht.Find(44)->_kv.first << endl;
	cout << ht.Find(4) << endl;
	ht.Print();

	ht.Insert(make_pair(-2, -2));
	ht.Print();

	cout << ht.Find(-2)->_kv.first << endl;
}

void TestHT2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

	//HashTable<string, int, HashFuncString> countHT;
	CloseHash::hashTable<string, int> countHT;
	for (auto& str : arr)
	{
		auto ptr = countHT.Find(str);
		if (ptr)
		{
			ptr->_kv.second++;
		}
		else
		{
			countHT.Insert(make_pair(str, 1));
		}
	}

	countHT.Print();
}

int main()
{
	TestHT2();
}