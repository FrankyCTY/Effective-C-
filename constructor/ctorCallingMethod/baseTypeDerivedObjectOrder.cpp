#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent CTOR" << endl;
		Test();
	}

	void SayHi()
	{
		cout << "Parent Said Hi" << endl;
	}

	virtual void Test()
	{
		cout << "Parent Test" << endl;
	};
};

class Child : public Parent
{
public:
	Child()
	{
		cout << "Child CTOR" << endl;
		Test();
	}

	void SayHi()
	{
		cout << "Child Said Hi" << endl;
	}

	virtual void Test()
	{
		cout << "Child Test" << endl;
	}
};

int main()
{
	Parent *child = new Child();
	child->SayHi();

	delete child;
	return 0;
};

// Parent CTOR
// Parent Test
// Child CTOR
// Child Test
// Parent Said Hi