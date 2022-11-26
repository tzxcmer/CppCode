#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef int int32;
typedef string FString;
//using vector = TArray;
//typedef vector<FCrewCard> TArray<FCrewCard>;

//shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//{
//	if (_ptr != nullptr)
//	{
//		delete _ptr;
//		delete _pcount;
//	}
//	if (_ptr == sp._ptr)
//		return *this;
//	_ptr = sp._ptr;
//	_pcount = sp.pcount;
//	(*_pcount)++;
//
//	reurn* this;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//	return 0;
//}


//template<class T>
//class shared_ptr
//{
//public:
//	shared_ptr(T* ptr = nullptr)
//		:_ptr(ptr)
//		,_Pcount(new int(1))
//	{}
//
//	Release()
//	{
//		if (--(*_Pcount) == 0)
//		{
//			delete _ptr;
//			delete _Pcount;
//		}
//	}
//
//	~shared_ptr()
//	{
//		Release();
//	}
//
//	shared_ptr(cosnt shared_ptr<T>& sp)
//		:_ptr(sp.ptr)
//		,_Pcount(sp._Pcount)
//	{
//		(*_Pcount)++;
//	}
//
//	shared_ptr<T>& operator=(cosnt shared_ptr<T>& sp)
//	{
//		if (_ptr == sp._ptr)
//		{
//			return *this;
//		}
//
//		Release();
//
//		_ptr = sp._ptr;
//		_Pcount = sp._Pcount;
//		(*_Pcount)++;
//
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//	int* _Pcount;
//};

#include<unordered_map>

int expressiveWords(string s, vector<string>& words) {
    unordered_map<char, int> hashmap;
    for (auto& ch : s)
        hashmap[ch]++;
    int sum = 0;

    for (int i = 0;i < words.size();i++)
    {
        unordered_map<char, int> hash;
        for (int j = 0;j < words[i].size();j++)
        {
            hash[words[i][j]]++;
        }
        bool flag = true;
        for (int j = 0;j < words[i].size();j++)
        {
            if (!hashmap.count(words[i][j]))
            {
                flag = false;
                break;
            }
            if (j > 0)
                if (words[i][j] == words[i][j - 1])
                    continue;

            if (hashmap[words[i][j]] == hash[words[i][j]])
                continue;
            if (hashmap[words[i][j]] < 3 || hashmap[words[i][j]] < hash[words[i][j]])
                flag = false;
        }
        int a = 0;
        if (s.size() >= words[i].size() && hashmap.size() > hash.size())
        {
            if (hashmap.size() != hash.size())
                flag = false;
            for (int j = 0;j < s.size();j++)
                if (!hash.count(s[j]))
                    flag = false;
        }
        else
        {
            flag = false;
        }

        if (flag)
            sum++;
    }

    return sum;
}

int main()
{
	string s = { "heeellooo" };
	vector<string> words{ "hello" };
	expressiveWords(s, words);
}
