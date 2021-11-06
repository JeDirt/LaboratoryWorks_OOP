#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;





// Task 1
class Animal
{

public:


	Animal(const string name) : Name(name) {}
	Animal() :Animal("animal") {}
	
	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Animal() {}


public:


	const string& GetName()const { return this->Name; }
	void SetName(const string name) { this->Name = name; }

	virtual const string MakeSound()const = 0;


private:


	string Name;


};

class Dog : public Animal
{
public:


	Dog() : Animal() {}
	Dog(const string name) { this->SetName(name); }

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Dog() {}


public:


	virtual const string MakeSound()const override { return "Woof, woof!"; }


};
class Cat : public Animal
{
public:


	Cat() : Animal() {}
	Cat(const string name) { this->SetName(name); }

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Cat() {}


public:


	virtual const string MakeSound()const override { return "Meow, meow!"; }


};


void ListenAnimals()
{

	vector<unique_ptr<Animal>>animals;

	animals.push_back(make_unique<Cat>(Cat("Cat")));
	animals.push_back(make_unique<Dog>(Dog("Dog")));

	for (auto it = animals.begin(); it != animals.end(); ++it)
	{
		cout << (*it).get()->MakeSound() << endl;
	}

}





// Task 2
class Shape
{

public:


	Shape(const int color) : Color(color) {}
	Shape() : Shape(0) {}

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Shape() {}


public:


	virtual void Draw() {}
	virtual const double GetArea()const {}

	const int GetColor()const { return this->Color; }
	void SetColor(const int color)
	{
		this->Color = color;
	}


public:


	// Using library defined PI value
	const double PI{ M_PI };


private:


	int Color;


};
class Square : public Shape
{

public:


	Square() : Shape(), Side(0) {}
	Square(const int color, const double side) : Side(side) { this->SetColor(color); }
	
	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Square() {}


public:


	virtual const double GetArea()const override {}
	virtual void Draw()override {}


private:


	double Side;


};





// Task 3
class IMovable
{

public:


	virtual ~IMovable() {}

	virtual void SetX(const double x) = 0;
	virtual void SetY(const double y) = 0;

	virtual const double GetX()const = 0;
	virtual const double GetY()const = 0;

	virtual void MoveTo(const double x, const double y) = 0;


};
class Point : public IMovable
{

public:


	Point(const double X, const double Y) : X(X), Y(Y) {}
	Point() : Point(0, 0) {}


	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Point() {}


public:


	void SetX(const double x)override { this->X = x; }
	void SetY(const double y)override { this->Y = y; }

	const double GetX()const override { return this->X; }
	const double GetY()const override { return this->Y; }

	void MoveTo(const double x, const double y) 
	{
		SetX(x);
		SetY(y);
	}


private:


	double X;
	double Y;


};





// Task 4
class IGPS
{
	
public:


	virtual ~IGPS() {}
	virtual const vector<double>& GetCoordinates()const = 0;


};
class ICellular 
{

public:


	virtual ~ICellular() {}

	virtual void MakeCall() = 0;
	virtual void ReceiveCall() = 0;


};


class Smartphone : public IGPS, public ICellular
{

public:

	
	Smartphone() { Coordinates = vector<double>(10, 0); }

	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Smartphone() {}


public:


	virtual const vector<double>& GetCoordinates()const override { return this->Coordinates; }
	virtual void MakeCall()override
	{
		cout << "Making call.." << endl;
	}
	virtual void ReceiveCall()override
	{
		cout << "Receiving call..." << endl;
	}


private:


	 vector<double>Coordinates;


};





// Task 5
template<class T>
class IDynamicIntArrayImpl
{

public:


	virtual ~IDynamicIntArrayImpl() {}

	virtual void add(const T value) = 0;
	virtual void add(const T value, const int index) = 0;

	virtual void remove() = 0;
	virtual void remove(const int index) = 0;

	virtual const int getSize()const = 0;
	virtual void clear() = 0;

	
};


template<class T>
class DynamicArray : public IDynamicIntArrayImpl<T>
{

public:


	DynamicArray() :DynamicArray(0) {}
	DynamicArray(const int size) 
	{
		if (size < 0) { throw exception("Invalid Array size"); }
		dynamicArray.reserve(size); 
	}
	
	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~DynamicArray() {}


public:


	virtual void add(const T value)override { this->dynamicArray.push_back(value); }
	virtual void add(const T value, const int index)override
	{ 

		if (index < 0 || index > dynamicArray.size())
		{ 
			throw exception("Invalid index!");
		}

		this->dynamicArray.insert(dynamicArray.begin()+index, value); 

	}

	virtual void remove(const int index) override
	{

		if (index < 0 || index > dynamicArray.size()) { throw exception("Invalid index!"); }
		this->dynamicArray.erase(dynamicArray.begin() + index); 
		
	}
	virtual void remove()override { remove(dynamicArray.size() - 1); }

	virtual const int getSize()const override { return this->dynamicArray.size(); }
	virtual void clear() { this->dynamicArray.clear(); }

	
private:


	vector <T> dynamicArray;


};
void CheckArrayValidity()
{

	DynamicArray<int>testArray;

	try
	{

		testArray.add(1);
		testArray.add(2);
		testArray.add(3);

		// Invalid index exception
		//testArray.add(44, -12);

		testArray.add(4);
		testArray.add(5);

	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}

}





// Task 6
class IIntStack
{

public:


	virtual ~IIntStack() {}

	virtual const int size()const = 0;
	virtual const bool empty()const = 0;

	virtual const int peek()const = 0;
	virtual void clear() = 0;

	virtual const int pop() = 0;
	virtual void push(const int value) = 0;


};





// Task 7
class Car
{

public:


	Car() : Car(0, 0, 0) {}
	Car(const int price,const int year,const int horsepower)
	{
		SetPrice(price);
		SetYear(year);
		SetHorsePower(horsepower);
	}
	
	// Imagine here copy and move constructors
	// I dont write it anymore in labs to not increase the number of lines

	virtual ~Car() {}


public:


	const double GetPrice()const { return this->Price; }
	const int GetYear()const { return this->Year; }
	const int GetHorsePower()const { return this->HorsePower; }

	void SetPrice(const double price)
	{
		if (price < 0) { throw exception("Invalid price!"); }
		this->Price = price;
	}
	void SetYear(const int year)
	{
		if (year < 1800 || year >2021) { throw exception("Invalid year!"); }
		this->Year = year;
	}
	void SetHorsePower(const int horsePower)
	{
		if (horsePower < 0) { throw exception("Invalid Horse Power!"); }
		this->HorsePower = horsePower;
	}

	void PrintCarInfo()
	{

		cout << this->GetPrice() << "\t"
			 << this->GetYear() << "\t" 
			 << this->GetHorsePower() << endl;

	}


public:


	bool operator > (const Car& other)
	{

		// Compare by price
		if (this->Price < other.Price) { return true; }

		// If price is equal
		if(this->Price == other.Price)
		{

			// Compare by year
			if (this->Year > other.Year) { return true; }

			// If year is equal
			if(this->Year == other.Year)
			{

				// Compare by horse power
				if (this->HorsePower > other.HorsePower) { return true; }

			}


		}

		return false;
	}
	bool operator < (const Car& other)
	{
		if (this->Price < other.Price) { return false; }

		if (this->Price == other.Price)
		{

			if (this->Year > other.Year) { return false; }
			if (this->Year == other.Year)
			{
				if (this->HorsePower > other.HorsePower) { return false; }
			}

		}

		return true;
	}
	bool operator ==(const Car& other)
	{

		return this->Price == other.Price &&
		this->Year == other.Year &&
		this->HorsePower == other.HorsePower;

	}
	bool operator !=(const Car& other)
	{

		return !(this->Price == other.Price &&
			this->Year == other.Year &&
			this->HorsePower == other.HorsePower);

	}


private:


	double Price;
	int Year;
	int HorsePower;


};
void PrintSortedCars()
{

	vector<Car>vec;
	vec.push_back(Car(10, 2000, 100));
	vec.push_back(Car(10, 2000, 1000));
	vec.push_back(Car(87, 2000, 100));
	vec.push_back(Car(12, 2000, 100));

	sort(vec.begin(), vec.end(), [&](Car c1, Car c2) {return c1 > c2; });


	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i].PrintCarInfo();
	}

}





int main()
{
   
	Dog d("fdf");
	cout << d.GetName();
	//ListenAnimals();
	//CheckArrayValidity();
	//PrintSortedCars();


	return 0;

}


