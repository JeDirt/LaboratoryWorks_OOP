#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;


class IntStack 
{

public:


	IntStack(const int stack_size) : Stack(stack_size) {}
	IntStack() : Stack(0) {}

	IntStack(const IntStack& ref)
	{
		this->Stack = { ref.Stack };
	}
	IntStack& operator = (const IntStack& ref)
	{

		if (this == &ref) { return *this; }

		this->Stack = { ref.Stack };

		return *this;

	}

	IntStack(IntStack&& ref)noexcept
	{

		this->Stack = { ref.Stack };
		ref.Stack.clear();

	}
	IntStack& operator = (IntStack&& ref)noexcept
	{

		if (this == &ref) { return *this; }

		this->Stack = { ref.Stack };
		ref.Stack.clear();

		return *this;

	}

	virtual ~IntStack() {}


public:


	const int size()const { return this->Stack.size(); }
	const bool empty()const { return this->size() == 0; }

	const int peek()const { return this->Stack[this->size()-1]; }
	void clear() { this->Stack = vector{ 0 }; }
	
	const int pop()
	{

		// Put returned value to store temporarily, return this value,
		// and get rid of that element in stack

		if (this->empty()) { return 0; }

		int TopOfStack = peek();
		this->Stack.erase(Stack.end() - 1);

		return TopOfStack;

	}
	void push(const int value) { this->Stack.push_back(value); }


private:

	vector <int> Stack;
	
};


class Student
{

public:


	Student(const string name, const string surname) : FirstName(name), LastName(surname) { this->Grades.reserve(0); }
	Student() :Student("unknown", "unknown") {}

	Student(const Student& ref)
	{

		this->FirstName = ref.FirstName;
		this->LastName = ref.LastName;
		this->Grades = ref.Grades;

	}
	Student& operator = (const Student& ref)
	{

		if (this == &ref) { return *this; }

		this->FirstName = ref.FirstName;
		this->LastName = ref.LastName;
		this->Grades = ref.Grades;

		return *this;

	}

	Student(Student&& ref)noexcept
	{

		this->FirstName = ref.FirstName;
		this->LastName = ref.LastName;
		this->Grades = ref.Grades;

		ref.FirstName.clear();
		ref.LastName.clear();
		ref.Grades.clear();

	}
	Student& operator = (Student&& ref)noexcept
	{

		if (this == &ref) { return *this; }

		this->FirstName = ref.FirstName;
		this->LastName = ref.LastName;
		this->Grades = ref.Grades;

		ref.FirstName.clear();
		ref.LastName.clear();
		ref.Grades.clear();

		return *this;

	}

	virtual ~Student() {}


public:


	const string& GetFirstName()const {}
	const string& GetLastName()const {}

	void SetFirstName(const string firstname) {}
	void SetLastName(const string lastname) {}


private:


	const int GetStudentFails()const {}


private:


	string FirstName;
	string LastName;

	vector<int>Grades;


};
class StudentGroup
{

public:


	StudentGroup(const string Title) : Title(Title) { this->Group.reserve(0); }
	StudentGroup() : StudentGroup("default") {}

	StudentGroup(const StudentGroup& ref)
	{
		this->Group = ref.Group;
		this->Title = ref.Title;
	}
	StudentGroup& operator = (const StudentGroup& ref)
	{

		if (this == &ref) { return *this; }

		this->Group = ref.Group;
		this->Title = ref.Title;

		return *this;

	}

	StudentGroup(StudentGroup&& ref)noexcept
	{

		this->Group = ref.Group;
		this->Title = ref.Title;

		ref.Group.clear();
		ref.Title.clear();

	}
	StudentGroup& operator = (StudentGroup&& ref)noexcept
	{

		if (this == &ref) { return *this; }

		this->Group = ref.Group;
		this->Title = ref.Title;

		ref.Group.clear();
		ref.Title.clear();

		return *this;

	}


	virtual ~StudentGroup() {}


public:


	const string& GetTitle()const {}
	void AddStudent(const Student Student) {}
	const Student& GetStudentByLastName()const {}


private:


	void SortStudentsByLastName() {}


private:


	vector<Student> Group;
	string Title;

	
};




int main()
{
	


	return 0;

}
