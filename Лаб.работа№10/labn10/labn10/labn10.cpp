#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include<numeric>



using namespace std;



// Task 1
int maxLength(const set<string> &_set)
{

	if (_set.empty()) { return  0; }

	// Find max string in set
	return (*max_element(_set.begin(), _set.end(),
		[&](string s1, string s2) { return s1.size() < s2.size(); }
		   )).size(); // Getting it's size and return as result

}


// Task 2
set<string> removeEvenLength(set<string>& _set)
{

	for (auto it = _set.begin(); it != _set.end(); ++it)
	{

		// erase() returns iterator to the next element of end(), so if we invalidate current element we must handle it to come next
		if ((*it).size() % 2 == 0) { it = _set.erase(it); }

	}

	return _set;

}


// Task 3
int numInCommon(vector<int>& vec1, vector<int>& vec2)
{

	set<int>_set1(vec1.begin(),vec1.end());
	set<int>_set2(vec2.begin(), vec2.end());

	int CommonCount = 0;
	for (auto el : _set2)
	{
		if (_set1.find(el) != _set1.end()) { CommonCount++; }		
	}

	return CommonCount;

}


// Task 4
bool isUnique(const map<string,string> &_map)
{

	set<string> _set;

    for(auto pair : _map)
	{

		string value = pair.second; 

		if (_set.find(value) != _set.end()) { return false; }
		_set.insert(value);

    }

    return true;

}


// Task 5
map<string, int>intersect(map<string, int>& map1, map<string, int>& map2)
{

	map<string, int>result;


	auto FirstMap_it = map1.begin();
	auto SecondMap_it = map2.begin();

	
	// Iterate through the maps
	while (FirstMap_it != map1.end() && SecondMap_it != map2.end())
	{

		if (*FirstMap_it < *SecondMap_it) { ++FirstMap_it; }
		else if (*FirstMap_it > *SecondMap_it) { ++SecondMap_it; }
			
		else
		{
			*inserter(result,result.begin()) = *FirstMap_it;
			++FirstMap_it;
			++SecondMap_it;
		}

	}

	return result;

}


// Task 6
map<string, int>reverse(const map<int, string>& _map)
{

	map<string, int> temp;
	for (auto it = _map.begin(); it !=_map.end(); ++it)
	{
		
		pair<string, int>p((*it).second, (*it).first);
		temp.insert(p);

	}

	return temp;

}


// Task 7
int rarest(map<string, int>& _map)
{

	vector< pair<string, int> > vec;

	copy(_map.begin(), _map.end(), back_inserter(vec));

	make_heap(vec.begin(), vec.end(), 
	[](const pair<string, int>& a, const pair<string, int>& b)
	{ return a.second < b.second; });
	
	return vec.back().second;

}


// Task 8
int maxOccurences(vector<int>& vec)
{

	if (vec.empty()) { return 0; }

	map<int, int> frequencyMap;

	int MaxFrequency = 0;
	int FrequencyCount = 0;

	for (auto el : vec)
	{

		int temp = ++frequencyMap[el];
		if (temp > MaxFrequency)
		{
			MaxFrequency = temp;
			FrequencyCount++;
		}

	}

	return FrequencyCount;

}


int main()
{


	return 0;
}

