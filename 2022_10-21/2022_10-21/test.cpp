#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;




static int n = 0;
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1 = 1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2 = 2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1 " <<n++<< endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d = 3;
};



//int main()
//{
//	
//
//	Derive d;
//	
//
//	
//	Base1* ptr1 = &d;
//	ptr1->func1();
//
//	Base2* ptr2 = &d;
//	ptr2->func1();
//
//	//d.func1();
//
//	return 0;
//}

class A
{
public:
	void print()
	{
		cout << "A" << endl;
	}

};


class B :A
{
public:
	void print()
	{
		cout << "B" << endl;
	}
private:
	int data;
};

class C : public B
{
public:

	void print()
	{
		//A::print();
	}
};

int main()
{
	//A* a = new C();
	//delete a;

	/*A a (5, 10);
	int* pint = (int*)&a;
	*(pint + 0) = 200;
	*(pint + 1) = 100;
	cout << a.geta() << endl;
	cout << a.getb() << endl;*/
}


B play(B b)
{
	return b;
}


class parent
{
	int i;
protected:
	int x;
public:
	parent()
	{
		x = 0;
		i = 0;
	}

	void change()
	{
		x++, i++;
	}
	void display()
	{
		cout << "pa" << endl;
	}
};


class son : public parent
{
public:
	void modify()
	{
		x++;
	}
	void display()
	{
		cout << "so" << endl;
	}
};

void print(parent a)
{
	a.display();
}

//int main()
//{
//	/*const int* p = 0;
//	int const  a = 5;
//	p = &a;
//	B temp = play(5);*/
//	/*B b;
//	C c;*/
//
//	son a;
//	parent b;
//	/*a.display();
//	a.change();
//	a.modify();
//	a.display();
//	b.change();
//	b.display();*/
//	print(b);
//}


#include<iostream>
#include<vector>
using namespace std;

//int main()
//{
//	int n;
//	int sum = 0;
//	int mod = 1;
//	int ans = 0;
//	cin >> n;
//	vector<int> cnt(n, 0);
//	vector<int> num(n, 0);
//	for (int i = 0;i < n;i++)
//	{
//		cin >> cnt[i];
//		sum += cnt[i];
//		mod *= cnt[i];
//		num[cnt[i]]++;
//	}
//	if (sum > mod)
//		ans++;
//	for (int i = n - 1;i >= 0;i--)
//	{
//		sum -= cnt[i];
//		mod = mod / cnt[i];
//		if (sum > mod)
//		{
//			ans += num[cnt[i]]--;
//		}
//
//	}
//	cout << ans << endl;
//	return 0;
//
//}
class A0
{
public:
	A0(const char* s1)
	{
		cout << s1 << endl;
	}
};

class B0 : virtual public A0
{
public:
	B0(const char* s1,const char* s2)
		:A0(s1)
	{
		cout << s2<< endl;
	}
};

class C0 : virtual public A0
{
public:
	 C0(const char* s1, const char* s2)
		 :A0(s1)
	{
		cout << s2 << endl;
	}
};
class D0 : public B0,public C0
{
public:
	D0(const char* s1, const char* s2, const char* s3, const char* s4)
		:B0(s1,s2),C0(s1,s3),A0(s1)
	{
		cout << s4 << endl;
	}
};





//int main()
//{
//	D0* p = new D0("a","b","c","d");
//	
//	
//}