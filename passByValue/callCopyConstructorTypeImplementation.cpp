#include <iostream>

class Person
{
public:
	Person()
	{
		std::cout << "person" << std::endl;
	};
	Person(const Person &rhs)
	{
		std::cout << "person copy constructor" << std::endl;
	};
	virtual ~Person()
	{
		std::cout << "destructure person" << std::endl;
	};
	virtual void DoSomething() const // note compiler forces us to use const
	{
		std::cout << "Person Doing Something" << std::endl;
	}
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
		std::cout << "student copy constructor" << std::endl;
	};
	virtual ~Student()
	{
		std::cout << "destructure student" << std::endl;
	};
	virtual void DoSomething() const // note compiler forces us to use const
	{
		std::cout << "Student Doing Something" << std::endl;
	}
};

void test(Person p) // NOTE: Using base class type here & passing by value
{
	std::cout << "validate student" << std::endl;
	p.DoSomething(); // Output: Student Doing Something
}

int main()
{
	Student student;

	test(student); // Passing derived class object

	// Student student;
	// Person p = student;
	// p.DoSomething();
}

// Output
// person
// student
// validate student
// Student Doing Something
// destructure student
// destructure person