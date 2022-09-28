#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

#include <time.h>

#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

void test_stack()
{
	
	tzx::stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}


void test_queue()
{

	tzx::queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}


void test_priority_queue()
{
	// 默认大的优先级高
	tzx::priority_queue<int> pq;
	//std::less<int> ls;
	//std::greater<int> gt;
	//std::priority_queue<int> pq(ls);

	pq.push(3);
	pq.push(1);
	pq.push(2);
	pq.push(5);
	pq.push(0);
	pq.push(1);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	int a[] = { 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	tzx::priority_queue<int> heap1(a, a+sizeof(a)/sizeof(int));
	tzx::priority_queue<int, vector<int>, greater<int>> heap2(a, a + sizeof(a) / sizeof(int));

	while (!heap1.empty())
	{
		cout << heap1.top() << " ";
		heap1.pop();
	}
	cout << endl;
}


int main()
{
	//test_stack();
	//test_queue();
	test_priority_queue();
}