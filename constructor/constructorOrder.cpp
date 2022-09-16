#include <iostream>

class MimicStringClass
{
public:
	MimicStringClass()
	{
		std::cout << "other" << std::endl;
	}
	MimicStringClass(const MimicStringClass &rhs)
	{
		std::cout << "COPY other" << std::endl;
	}
	virtual ~MimicStringClass()
	{
		std::cout << "destructure other" << std::endl;
	};
};

class Person
{
public:
	Person()
	{
		std::cout << "person" << std::endl;
	};
	Person(const Person &rhs)
	{
		std::cout << "COPY person" << std::endl;
		name = rhs.name;
		address = rhs.address;
	}
	virtual ~Person()
	{
		std::cout << "destructure person" << std::endl;
	};

private:
	std::string name;
	std::string address;
};

class Student : public Person
{
public:
	Student()
	{
		std::cout << "student" << std::endl;
	};
	Student(const Student &rhs)
	{
		std::cout << "COPY student" << std::endl;
		schoolName = rhs.schoolName;
		schoolAddress = rhs.schoolAddress;
	}
	virtual ~Student()
	{
		std::cout << "destructure student" << std::endl;
	};

private:
	std::string schoolName;
	std::string schoolAddress;
	// Used to demonstrate the timing/order of the constructor/destructor called for string class
	MimicStringClass mimicString;
};

bool validateStudent(Student s)
{
	std::cout << "validate student" << std::endl;
	return true;
}

int main()
{
	Student plato;

	bool result = validateStudent(plato);
}