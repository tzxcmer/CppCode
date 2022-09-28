#pragma once



namespace tzx
{
	template<class T,class Container = vector<T>,class Compare = std::less<T>>
	class priority_queue
	{
	public:

		priority_queue()
		{}

		template<class InputIerator>
		priority_queue(InputIerator first, InputIerator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 1 - 1) / 2;i >= 0;i--)
			{
				adjust_down(i);
			}
		}


		void adjust_up(size_t child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			int child = parent * 2+1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child+1], _con[child]))
				{
					++child;
				}
				
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		T& top()
		{
			return _con[0];
		}

		const T& top() const
		{
			return _con[0];
		}


		bool empty()  const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}
