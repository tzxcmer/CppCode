#pragma once

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace tzx
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_irerator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		string(const char* s = "")
		{
			_size = strlen(s);
			_capacity = _size;
			_str = new char[_capacity+ 1];

			strcpy(_str, s);
		}

		//深拷贝(传统写法)
		/*string(const string& str)
			:_str(new char[str._capacity+1])
			,_size(str._size)
		    ,_capacity(str._capacity)
		{
			strcpy(_str, str._str);
		}*/

		void swap(string& tmp)
		{
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}

		//现代写法
		string(const string& str)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(str._str);
			swap(tmp);
		}

		//string& operator= (const string& str)
		//{
		//	if (this != &str)
		//	{
		//		//delete[] _str;
		//		//_str = new char[str._capacity + 1];
		//		char *tmp = new char[str._capacity + 1];
		//		strcpy(tmp, str._str);
		//		delete[] _str;
		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//}

		/*string& operator= (const string& str)
		{
			if (this != &str)
			{
				string tmp(str._str);
				swap(tmp);
			}
			return *this;
		}*/

		string& operator= (string str)
		{
			swap(str);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const size_t size()const 
		{
			return _size;
		}

		size_t size()
		{
			return _size;
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);

			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);

				for (size_t i = 0;i < n;i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size +len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos+len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, s, len);
			_size += len;
			return *this;
		}

		void push_back(char ch)
		{
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';*/
			insert(_size, ch);
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size  = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}


		void append(const char* s)
		{
			/*int len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + len, s);
			_size += len;*/
			insert(_size, s);
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos;i < _size;i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}


		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);

			char* tmp = strstr(_str+pos,sub);

			if (tmp == nullptr)
			{
				return npos;
			}
			else
			{
				return tmp - _str;
			}
		}


		string substr(size_t pos = 0, size_t len = npos) const
		{
			assert(pos < _size);
			size_t realLen = len;
			if (realLen == npos || realLen > _size)
			{
				realLen = _size;
			}
			string sub;
			for (size_t i = pos;i < realLen;i++)
			{
				sub += _str[i];
			}
			return sub;
		}


		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	    /*
		* 
		* 运算符重载
		* 
		*/

		string& operator+=(char ch)
		{
			push_back(ch);

			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s) const
		{
			return (*this > s || *this == s);
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

	private:
		int _size;
		int _capacity;
		char* _str;

	public:
		const static size_t npos = -1;
	};


	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0;i < s.size();i++)
		{
			out << s[i];
		}
		return out;
	}


	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		//in >> ch;
		ch = in.get();
		const size_t N = 32;
		char buff[N];
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			in >> ch;
		}
		return in;
	}
}


