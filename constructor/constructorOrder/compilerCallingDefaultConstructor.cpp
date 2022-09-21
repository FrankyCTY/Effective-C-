#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent constructor" << endl;
	};

	Parent(const Parent &parent)
	{
		cout << "Parent Copy Constructor" << endl;
	};

	Parent &operator=(const Parent &rhs)
	{
		cout << "Parent Copy Assignment Operator" << endl;
		return *this;
	};
};

class Child : public Parent
{
public:
	Child(const string name) : _name(name)
	{
		cout << "Child Constructor" << endl;
	};

	// Compiler will call default constructor but not calling parent copy constructor
	// Because we are not explicit deciding which member function to call in member initialization list
	Child(const Child &child)
	// Same as 	Child(const Child &child) : Parent()
	{
		cout << "Child Copy Constructor" << endl;
		_name = child._name;
	};

	Child &operator=(const Child &rhs)
	{
		cout << "Child Copy Assignment Operator" << endl;
		_name = rhs._name;
		return *this;
	};

	~Child()
	{
		cout << "Child Destructor" << endl;
	};

	string GetName() const
	{
		return _name;
	}

private:
	string _name;
};

string &work(string &str)
{
	return str;
};

int main()
{
	Child c1("c1");
	Child c2 = c1;

	cout << c2.GetName() << endl;

	return 0;
}

// =============== Output ===============
// Parent constructor
// Child Constructor
// Parent constructor <-
// Child Copy Constructor <-
// c1
// Child Destructor
// Child Destructor