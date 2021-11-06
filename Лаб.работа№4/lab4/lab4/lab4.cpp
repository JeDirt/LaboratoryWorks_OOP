#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;


// Task1
class Point
{

public:


	Point(const int x, const int y) :x(x), y(y) {}
	Point() : Point(0, 0) {}
	virtual ~Point() {}


public:


	// Getting values
	const int getX()const { return this->x; }
	const int getY()const { return this->y; }


	// Getting coordinates in understandable format
	virtual const string toString() { return makeBraced(convertToStringPrimary()); }
	

	// Calculate distances between points/from origin
	const double distance(const Point point)
	{ 
		return sqrt(getIntermediateSum(this->x, point.getX(), this->y, point.getY()));
	}
	virtual const double distanceFromOrigin()
	{
		return sqrt(getIntermediateSum(0, this->x, 0, this->y));
	}
	

	// Setting new location
	virtual void setLocation(const int x, const int y)
	{

		this->x = x;
		this->y = y;

	}
	

protected:


	// Intermediate calculating for the next step in formula, made for comfortable calculating in derived classes
	const double getSquaredValue(const int coord1,const int coord2)
	{
		return  (pow(coord1 - coord2, 2));
	}
	virtual const double getIntermediateSum(const int coord1,const int coord2,const int coord3,const int coord4)
	{
		return getSquaredValue(coord1, coord2) + getSquaredValue(coord3, coord4);
	}


	// Returns coordinates in braced format
	string makeBraced(const string coordinates)
	{
		return "(" + coordinates + ")";
	}


	// Intermediate converting to string, made for comfortable converting in derived classes
	virtual const string convertToStringPrimary()
	{
		return to_string(x) + "," + to_string(y);
	}


protected:


	int x;
	int y;


};
class Point3D : public Point
{

public:


	Point3D(const int x,const int y,const int z) : Point(x,y)
	{
		this->z = z;
	}
	Point3D() : Point3D(0, 0, 0) {}
	virtual ~Point3D() {}


public:


	// Getting Z value
	const int getZ()const { return this->z; }


	// Getting coordinates in understandable format
	virtual const string toString() override
	{
		return Point::makeBraced(convertToStringPrimary());
	}


	// Calculate distances between points/from origin
	const double distance(const Point3D point)
	{

		return sqrt(Point::getIntermediateSum(this->x, point.getX(), this->y, point.getY()) 
			+ getSquaredValue(this->z, point.getZ()));

	}
	virtual const double distanceFromOrigin()override
	{
		return sqrt(Point::getIntermediateSum(0, this->getX(), 0, this->getY()) + getSquaredValue(0, this->z));
	}
	
	
	// Setting new location( z is always 0)
	virtual void setLocation(const int x,const int y)override
	{
		Point::setLocation(x, y);
		this->z = 0;
	}
	void setLocation(const int x,const int y,const int z)
	{
		Point::setLocation(x, y);
		this->z = z;
	}


protected:


	virtual const string convertToStringPrimary()override
	{
		return Point::convertToStringPrimary() + "," + to_string(this->z);
	}
	

private:


	int z;


};



// Task2
struct Employee
{
	// just BASED employee
};
class Item
{
public:

	
	Item(const double price,const string name,const double discount) : Price(price), Name(name), Discount(discount) {}
	Item() : Item(0, "unknown", 0) {}

	Item(const Item& ref)
	{

		this->Price = ref.Price;
		this->Name = ref.Name;
		this->Discount = ref.Discount;

	}
	Item& operator = (const Item& ref)
	{

		if (this == &ref) { return *this; }

		this->Price = ref.Price;
		this->Name = ref.Name;
		this->Discount = ref.Discount;

		return *this;

	}

	Item(Item&& ref)noexcept
	{

		this->Price = ref.Price;
		this->Name = ref.Name;
		this->Discount = ref.Discount;

		ref.Price = 0;
		ref.Name.clear();
		ref.Discount = 0;

	}
	Item& operator = (Item&& ref)noexcept
	{

		if (this == &ref) { return *this; }

		this->Price = ref.Price;
		this->Name = ref.Name;
		this->Discount = ref.Discount;

		ref.Price = 0;
		ref.Name.clear();
		ref.Discount = 0;

		return *this;

	}

	virtual ~Item() {}


public:


	// Getting values of the item
   const double getPrice()const { return this->Price; }
   const string& getName()const { return this->Name; }
   const double getDiscount()const { return this->Discount; }


private:


	double Price{ 0.0 };
	string Name;
	double Discount{ 0.0 };


};

class GroceryBill
{

public:


	GroceryBill(const Employee clerk) : Clerk(clerk)
	{
		this->ItemsBucket.reserve(0);
	}
	GroceryBill() : GroceryBill(Employee{})
	{
		this->ItemsBucket.reserve(0);
	}

	GroceryBill(const GroceryBill& ref)
	{

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;
		
	}
	GroceryBill& operator = (const GroceryBill& ref)
	{

		if (this == &ref) { return *this; }

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;

		return *this;

	}

	GroceryBill(GroceryBill&& ref)noexcept
	{

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;

		ref.Clerk = Employee{};
		ref.ItemsBucket.clear();

	}
	GroceryBill& operator = (GroceryBill&& ref)noexcept
	{

		if (this == &ref) { return *this; }

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;

		ref.Clerk = Employee{};
		ref.ItemsBucket.clear();

		return *this;

	}

	virtual ~GroceryBill() {}


public:


	// Add item to the bill
	void add(const Item item)
	{
		ItemsBucket.push_back(move(item));
	}


	// Get total price of all items in the bill
	virtual const double getTotal()const
	{
		return accumulate(ItemsBucket.begin(), ItemsBucket.end(), 0, [](int total, Item item) {return total + item.getPrice(); });
	}


	// Print bill 
	void printReceipt()
	{

		for (auto& el : ItemsBucket)
		{
			cout << el.getName() << " \t" << el.getPrice() << endl;
		}

	}


protected:


	Employee Clerk;
	vector <Item> ItemsBucket;


};
class DiscountBill : public GroceryBill
{

public:


	DiscountBill(const Employee clerk,const bool isRegular) : GroceryBill(clerk), isRegularCustomer(isRegular) {}
	DiscountBill() : GroceryBill(), isRegularCustomer(false) {}
	
	DiscountBill(const DiscountBill& ref) 
	{
		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;
		this->isRegularCustomer = ref.isRegularCustomer;
	}
	DiscountBill& operator = (const DiscountBill& ref) 
	{

		if (this == &ref) { return *this; }

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;
		this->isRegularCustomer = ref.isRegularCustomer;

		return *this;

	}

	DiscountBill(DiscountBill&& ref)noexcept
	{

		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;
		this->isRegularCustomer = ref.isRegularCustomer;

		ref.Clerk = Employee{};
		ref.ItemsBucket.clear();
		ref.isRegularCustomer = false;

	}
	DiscountBill& operator = (DiscountBill&& ref)noexcept
	{

		if (this == &ref) { return *this; }


		this->Clerk = ref.Clerk;
		this->ItemsBucket = ref.ItemsBucket;
		this->isRegularCustomer = ref.isRegularCustomer;

		ref.Clerk = Employee{};
		ref.ItemsBucket.clear();
		ref.isRegularCustomer = false;


		return *this;

	}

	virtual ~DiscountBill() {}


public:


	// Get number of items with discount
	const int getDiscountCount()const
	{
		return count_if(ItemsBucket.begin(), ItemsBucket.end(), [&](Item item) {return item.getDiscount() > 0; });
	}


	// Get total price of all items in the bill, but taking into account the factor that customer is regular
	const double getTotal()const override
	{

		if (this->isRegularCustomer)
		{
			return GroceryBill::getTotal() - this->getDiscountAmount();
		}

		return GroceryBill::getTotal();
		
	}


	// Get total number of discount
	const double getDiscountAmount()const
	{
		return accumulate(ItemsBucket.begin(), ItemsBucket.end(), 0, [](int total, Item item) {return total + item.getDiscount(); });
	}


	// Get percentage of saved money
	const double getDiscountPercent()const
	{
		return 100 - (getTotal() * 100) / GroceryBill::getTotal();
	}


private:


	bool isRegularCustomer;


};



int main()
{
	
	

    return 0;

}


