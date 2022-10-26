#pragma once
#include<iostream>

namespace tzx
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			,_right(nullptr)
			,_key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if(cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);

			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}
		

		bool Find(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent->_right = cur;
				}
				else if (cur->_key > key)
				{
					parent->_left = cur;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//×óÎª¿Õ£¬ÓÒÎª¿Õ£¬×óÓÒ¶¼²»¿Õ

					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else
					{
						Node* minParent = cur;
						Node* min = cur->_right;
						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}
						std::swap(cur->_key, min->_key);
						if (minParent->_left == min)
						{
							minParent->_left = min->_right;
						}
						else
						{
							minParent->_right = min->_right;
						}
						delete min;
					}
					return true;
				}
			}
			return false;
		}

		void InOrder()
		{
			_inorder(_root);
			std::cout << std::endl;
		}


		BSTree() = default;


		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		BSTree(const BSTree<K>& t)
		{
			_root = _copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			std::swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			_Destory(_root);
		}

	private:
		Node* _root = nullptr;


		Node* _copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyRoot = new Node(root->_key);
			copyRoot->_left = _copy(root->_left);
			copyRoot->_right = _copy(root->_right);

			return copyRoot;
		}

		void _Destory(Node* root)
		{
			if (root == nullptr)
				return;
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
			root = nullptr;
		}

		void _inorder(Node* _root)
		{
			if (_root == nullptr)
				return;
			_inorder(_root->_left);
			std::cout << _root->_key <<" ";
			_inorder(_root->_right);
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false;
		}

		bool _FindR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return true;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{
				Node* del = root;

				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}

					std::swap(root->_key, min->_key);
					return _EraseR(root->_right, key);
				}
				delete del;
				return true;
			}
		}
	};


	
}
