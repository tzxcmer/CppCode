#define _CRT_SECURE_NO_WARNINGS 1

#include"BinarySearchTree.h"

void TestBSTree1()
{
	tzx::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.InsertR(e);
	}

	// ≈≈–Ú+»•÷ÿ
	t.InOrder();

	t.EraseR(3);
	t.InOrder();

	t.EraseR(8);
	t.InOrder();
	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
}



void TestBSTree2()
{
	tzx::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.InsertR(e);
	}

	tzx::BSTree<int> copy = t;
	copy.InOrder();
	t.InOrder();

	tzx::BSTree<int> t1;
	t1.Insert(2);
	t1.Insert(1);
	t1.Insert(3);

	copy = t1;
	copy.InOrder();
	t1.InOrder();
}
int main()
{
	TestBSTree2();
}