#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//模板函数
//template<class T>
//void MySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 6;
//	printf("%d %d\n", a, b);
//	MySwap(a, b);
//	printf("%d %d\n", a, b);
//}

//template<class T>
//class person {
//public:
//	person(T id,T age)
//	{
//		this->Age = age;
//		this->Id = id;
//	}
//	void Show()
//	{
//		cout << "ID:" << Id << "Age:" << Age << endl;
//	}
//public:
//	T Id;
//	T Age;
//};
//
//void test01()
//{
//	person<int>p(10, 20);
//	p.Show();
//}
//


//函数模板
//template<class T>
//void MySort(T* arr, int len)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < len;i++)
//	{
//		for (j = i + 1;j < len;j++)
//		{
//			T temp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = temp;
//		}
//	}
//}
//
//template<class T>
//void PrintArr(T* arr, int len)
//{
//	for (int i = 0;i < len;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test02()
//{
//	char chArr[] = {'a','c','b'};
//	int len = sizeof(chArr) / sizeof(chArr[0]);
//	PrintArr(chArr, len);
//	MySort(chArr, len);
//	PrintArr(chArr, len);
//}

//类模板
//template<class T>
//class Animal
//{
//public:
//	void Jiao()
//	{
//		cout << mAge << "岁动物在叫" << endl;
//	}
//public:
//	T mAge;
//};
//
//template<class T>
//class Cat : public Animal<T>{};
//
//
//void test03()
//{
//	Cat<int> cat;
//	cat.mAge = 10;
//	cat.Jiao();
//}

//类内实现
template<class T1,class T2>
class Person 
{
public:
	Person(T1 name ,T2 age)
	{
		this->Name = name;
		this->Age = age;
	}
	void Show()
	{
		cout << "名字:" << Name << " 年龄:" << Age << endl;
	}
public:
	T1 Name;
	T2 Age;
};

void test04()
{
	Person<string, int> p("AAa", 20);
	p.Show();
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
}