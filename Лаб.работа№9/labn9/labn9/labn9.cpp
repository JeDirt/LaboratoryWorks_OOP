#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>




using namespace std;




// Task 1
void removeShorterStrings(vector<string>& vec)
{

	const int SavedSize = vec.size();
	for (int i = 0; i < SavedSize / 2; i++)
	{

		if (vec[i].length() == vec[i + 1].length()) { vec.erase(vec.begin() + i); }
		else { vec.erase(vec.begin() + i); }
			
	}

}




// Task 2
void stutter(vector<string>& vec)
{

	const int SavedSize = vec.size();
	vec.resize(SavedSize * 2);

	for (size_t i = SavedSize - 1; i < SavedSize; --i)
	{

		vec[(i * 2) + 1] = vec[i];
		vec[i * 2] = move(vec[i]);

	}


	// or

	/*
	const int SavedSize = vec.size();
	vec.resize(SavedSize << 1);

	for (size_t i = SavedSize - 1; ~i; --i)
	{
		vec[(i << 1) | 1] = vec[i];
		vec[i << 1] = move(vec[i]);
	}
	*/
	

	// or

	/*
	const int SavedSize = vec.size();
	for (int i = 0; i < SavedSize; i++)
	{

		string temp = vec[i * 2];

		for (int j = 1; j < 2; j++)
		{
			vec.insert(vec.begin() + i * 2 + j, temp);
		}

	}
	*/
	

}




// Task 3
void swapPairs(vector<string>& vec)
{

	for (int i = 0; i < vec.size() / 2; i++) 
	{
		swap(vec[2 * i + 1], vec[2 * i]);
	}

}




// Task 4
void removeDuplicates(vector<string>& vec)
{
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
}




// Task 5
void markLength4(vector<string>& vec)
{

	for (int i = 0; i < vec.size(); i++) 
	{

		if (vec[i].length() == 4) 
		{
			vec.insert(vec.begin() + i, "****");
			i++;
		}

	}

}




// Task 6
bool isPalindrome(queue<int> &qeq)
{

	stack<int> stck;
	const int SavedSize = qeq.size();

	// Loop the queue and fill the stack 
	for (int i = 0; i < SavedSize; i++)
	{

		int ExecutedValue = qeq.front();
		qeq.pop();

		qeq.push(ExecutedValue);
		stck.push(ExecutedValue);

	}


	// Compare every stack value with every queue value
	for (int i = 0; i < SavedSize; i++)
	{

		int ExecutedValue = qeq.front();

		if (ExecutedValue != stck.top()) { return false; }
		qeq.push(ExecutedValue);

	}

	return true;

}




// Task 7
void reorder(queue<int>&_queue)
{

	stack<int> _stack;
	int it = 0;


	int SavedSize = _queue.size();

	for (int i = 0; i < SavedSize; i++) 
	{

		int num = _queue.front();
		_queue.pop();

		if (num < 0) { _stack.push(num); }
		else { _queue.push(num); it++; }
			
	}


	while (!_stack.empty()) 
	{
		_queue.push(_stack.top());
		_stack.pop();
	}

	for (int i = 0; i < it; i++) 
	{
		_queue.push(_queue.front());
		_queue.pop();
	}
	
}




// Task 8
void rearrange(queue<int>&_queue)
{

	stack<int>_stack;
	const int SavedSize = _queue.size();


	for (int i = 0; i < SavedSize; i++)
	{

		int ExecutedValue = _queue.front();
		_queue.pop();

		if (ExecutedValue % 2 == 0) { _stack.push(ExecutedValue); }
		else { _queue.push(ExecutedValue); }
			
	}


	for (int i = 0; i < 2; i++) 
	{

		while (!_queue.empty())
		{
			_stack.push(_queue.front());
			_queue.pop();
		}

		while (!_stack.empty()) 
		{
			_queue.push(_stack.top());
			_stack.pop();
		}

	}

}





int main()
{ 



	
	
	return 0; 

}


