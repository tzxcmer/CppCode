#pragma once


enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
	{}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// ��һ������������������ڵ�
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_node = left;
		}
		else
		{
			// ���������溢�Ӳ������ȵ��ҵ��Ǹ�
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			// ��һ���������������ҽڵ�
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}

			_node = right;
		}
		else
		{
			// ���Ӳ��Ǹ��׵�����Ǹ�����
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}
};

template<class K, class T, class KeyOfT>
struct RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}

		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT kot;

		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return  make_pair(iterator(_root), true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		//�ؼ���uncle
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			assert(grandfather);
			assert(grandfather->_col == BLACK);

			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//case1:uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//��������
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//     g 
					//   p   u
					// c
					// case2���ҵ���+��ɫ
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g 
						//   p   u
						//     c
						//case3:���ҵ���+��ɫ
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}

			}
			else
			{
				Node* uncle = grandfather->_left;
				//case1:uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//��������
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//     g 
					//   u   p
					//         c
					// case2��z����+��ɫ
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g 
						//   u   p
						//     c
						//case3:������+��ɫ
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;

		if (_root->_col == RED)
		{
			cout << "���ڵ㲻�Ǻ�ɫ" << endl;
			return false;
		}

		//��¼��ɫ��������
		int  benchmark = 0;

		return PrevCheck(_root, 0, benchmark);
	}

private:
	Node* _root = nullptr;

	bool PrevCheck(Node* root, int blackNum, int& benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark == 0)
			{
				benchmark = blackNum;
				return true;
			}

			if (blackNum != benchmark)
			{
				cout << "ĳ����ɫ�ڵ�����������" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}

		if (root->_col == BLACK)
			++blackNum;

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return PrevCheck(root->_left, blackNum, benchmark)
			&& PrevCheck(root->_right, blackNum, benchmark);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}

			subR->_parent = ppNode;
		}

	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}

			subL->_parent = ppNode;
		}

	}
};
