#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>



using namespace std;


// Task 1
template<class T>
class IStack
{

public:


	virtual ~IStack() {}

	virtual const bool empty()const = 0;
	virtual const int size()const = 0;

	virtual const T peek()const = 0;
	virtual void clear() = 0;

	virtual const T pop() = 0;
	virtual void push(const T value) = 0;


};

template<class T>
class Stack : public IStack<T>
{

public:


	Stack() {}
	virtual ~Stack() {}


public:


	const bool empty()const override { return stack.empty(); }
	const int size()const override { return stack.size(); }

	const T peek()const override{ return stack.back(); }
	void clear()override { stack.clear(); }

	const T pop()override
	{

		T temp = peek();
		stack.pop_back();

		return temp;

	}
	void push(const T value) { stack.push_back(value); }

	
private:


	vector<T>stack;


};

template <>
void Stack<string>::push(const string value)
{
	stack.push_back("New word:" + value);
}




// Task 3
class Printer
{

public:


	template<class T>
	void print(const vector<T> vec)
	{
		for_each(vec.begin(), vec.end(), [&](T value) {cout << value << " "; });
	}


};




// Task 5
template <class T>
bool contains(vector<T>vec, T searched)
{

	auto isContain = find(vec.begin(), vec.end(), searched);
	if (isContain != vec.end()) { return true; }

	return false;

}




// Task 6
template<class T1, class T2>
class ConcreteTwoTuple
{

public:


	ConcreteTwoTuple(T1 value1 = T1(),T2 value2=T2()) 
	{
		this->value1 = value1;
		this->value2 = value2;
	}
	virtual ~ConcreteTwoTuple() {}


public:


	 const tuple<T1, T2> GetTupleOfValues()const { return make_tuple(value1, value2); }


private:


	T1 value1;
	T2 value2;


};


template<class T1, class T2, class T3>
class ConcreteThreeTuple : protected ConcreteTwoTuple<T1, T2>
{

public:


	ConcreteThreeTuple(T1 value1 = T1(), T2 value2 = T2(), T3 value3 = T3()) : 
		ConcreteTwoTuple<T1, T2>(value1, value2)
	{
		this->value3 = value3;
	}
	virtual ~ConcreteThreeTuple() {}


public:


	const tuple<T1, T2, T3> GetTupleOfThreeValues()const
	{

		auto [a,b]=ConcreteTwoTuple<T1, T2>::GetTupleOfValues();
		return make_tuple(a, b, this->value3);
	}


private:


	T3 value3;


};






int main()
{
    
	
	ConcreteThreeTuple<int, string, int>obj;
	
	auto [a, b, c] = obj.GetTupleOfThreeValues();
	// or
	int d, e; string f;
	tie(d,f,e) = obj.GetTupleOfThreeValues();



    return 0;

}

