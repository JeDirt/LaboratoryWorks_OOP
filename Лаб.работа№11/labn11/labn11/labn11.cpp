#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>



using namespace std;



// Task 1
template <class T>
class NumberStack
{

public:


	struct  Iterator
	{

		Iterator(NumberStack& outer) :outer(outer) {}

		bool has_next()const { return outer._stack.size() > 0; }
		T next() { return outer.pop(); }

	private:

		NumberStack& outer;

	};


public:


	// Construct stack of given **size filled with **values
	NumberStack(const int size, T value) { _stack = vector<T>(size, value); }

	NumberStack() { _stack.reserve(0); }
	virtual ~NumberStack() {}


public:


	// Returns popped elements 
	const T& pop()
	{

		T temp = peek();
		_stack.pop_back();

		return temp;

	}


	// Add element to stack
	void push(const T data) { _stack.push_back(data); }


	// Check top element
	const T& peek()const
	{

		if (empty())
		{
			throw exception("Exception: empty stack!");
		}

		return _stack.back();

	}


	// Get size of stack
	int size()const { return _stack.size(); }


	// True when stack has no elements
	bool empty()const { return _stack.empty(); }


	// Delete all elements from stack
	void clear() { _stack.clear(); }


	// Creates iterator for current stack
	Iterator getIterator() { return Iterator(*this); }


private:


	vector<T>_stack;


};


// Task 2.1
vector<int> doubling(vector<int>& vec)
{

	transform(vec.begin(), vec.end(), vec.begin(), [&](auto el) {return el * 2; });
	return vec;

}


// Task 2.2
vector<string> copies3(vector<string>& vec)
{

	transform(vec.begin(), vec.end(), vec.begin(), [&](auto el) {return el += el + el; });
	return vec;

}


// Task 2.3
vector<string> noX(vector<string>& vec)
{

	vec.erase
	(

		remove_if(vec.begin(), vec.end(), [&](string el)
		{
			return any_of(el.begin(), el.end(), [&](auto el) { return el == 'x' || el == 'X'; });
		}

	), vec.end());

	return vec;
		
}


// Task 2.4
vector<int> no9(vector<int>& vec)
{

	vec.erase(remove_if(vec.begin(), vec.end(), [&](auto el) {return el % 10 == 9; }), vec.end());
	return vec;

}


// Task 2.5
vector<string> refinedStrings(vector<string>& vec)
{

	sort(vec.begin(), vec.end(), [&](string a, string b) {return greater<int>{}(a.size(), b.size()); });
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;

}


// Task 2.6
vector<string> flatten(vector<string>& vec)
{

	string Name, Surname;
	vector<string> transformed;
	
	for (size_t i = 0; i < vec.size(); i++)
	{

		stringstream(vec[i]) >> Name >> Surname;

		transformed.push_back(Name);
		transformed.push_back(Surname);

	}

	return transformed;

}



int main()
{



	return 0;

}
