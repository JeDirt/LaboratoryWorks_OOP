#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>
#include<random>
#include <ctime>


using namespace std;


class Person
{

public:


	Person(const string name, const string surname, int age) :Name(name), Surname(surname), Age(age) {}
	Person() :Person("undefined", "undefined", 0) {}
	
	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Person() {}


public:


	const string& GetName()const { return this->Name; }
	const string& GetSurname()const { return this->Surname; }
	const int GetAge()const { return this->Age; }

	void SetName(const string name) { this->Name = name; }
	void SetSurname(const string surname){ this->Surname = surname; }
	void SetAge(const int age){ this->Age = age; }
	
	virtual const string toString()
	{
		return "Human " + toStringIntermediateSample();
	}


protected:

	// General repeatable part of toString moved to separated method 
	const string toStringIntermediateSample() { return this->Surname + " " + this->Name + " ," + "age: " + to_string(this->Age); }

protected:


	string Name;
	string Surname;
	int Age{ 0 };


};


class Student : public Person
{

public:


	Student() : Person(), Group("undefined"), StudentCardID(0) {}
	Student
	(
		const string name, 
		const string surname, 
	    int age,
		const string group,
		long id
	) :

		// Init list
		Person(name, surname, age),
		Group(group), 
		StudentCardID(id) {}

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Student() {}
	

public:


	const string& GetGroup()const { return this->Group; }
	const int GetCardID()const { return this->StudentCardID; }

	void SetGroup(const string group) { this->Group = group; }
	void SetCardID(const long id) { this->StudentCardID = id; }

	const string toString()override
	{
		return "Student of the group " + 
			this->Group + 
			", " +
			toStringIntermediateSample() + 
			" Student card ID: " + 
			to_string(this->StudentCardID);
	}


private:


	string Group;
	long StudentCardID{ 0 };


};
class Lecturer : public Person
{

public:


	Lecturer() : Person(), Cathedra("undefined"), Salary(0.0) {}
	Lecturer
	(
		const string name,
		const string surname,
		int age,
		const string cathedra,
		long salary
	) :

		// Init list
		Person(name, surname, age),
		Cathedra(cathedra),
		Salary(salary) {}

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Lecturer() {}


public:


	const string& GetCathedra()const { return this->Cathedra; }
	const int GetSalary()const { return this->Salary; }

	void SetCathedra(const string cathedra) { this->Cathedra = cathedra; }
	void SetSalary(const double salary) { this->Salary = salary; }

	const string toString()override
	{
		return "Teacher of the cathedra " + 
			this->Cathedra + " " + 
			toStringIntermediateSample() + 
			". " + 
			"Salary " + 
			to_string(this->Salary);
	}


private:
	

	string Cathedra;
	double Salary{ 0 };


};


vector<unique_ptr<Person>> GeneratePeopleVector()
{

	// An instance of an engine
	random_device random_device;

	// Specify the engine and distribution
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> distribution{ 0, 2 };

	auto generator = [&distribution, &engine]() {	return distribution(engine); };


	vector<int> indexes(10);
	generate(begin(indexes), end(indexes), generator);


	vector<unique_ptr<Person>>people;
	for (size_t i = 0; i < indexes.size(); i++)
	{

		switch (indexes[i])
		{
		case 0:
			people.push_back(make_unique<Person>(Person{}));
			break;
		case 1:
			people.push_back(make_unique<Student>(Student{}));
			break;
		case 2:
			people.push_back(make_unique<Lecturer>(Lecturer{}));
			break;
		}

	}


	return people;

}
void PrintObjectsInfo()
{

	for (size_t i = 0; i < GeneratePeopleVector().size(); i++)
	{
		cout << GeneratePeopleVector()[i].get()->toString() << endl;
	}

}


int main()
{
	
	PrintObjectsInfo();
	


	return 0;
}

