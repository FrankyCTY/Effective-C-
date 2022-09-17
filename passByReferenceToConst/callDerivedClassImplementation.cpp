#include <iostream>

class Person
{
public:
	Person()
	{
		std::cout << "person" << std::endl;
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
	virtual ~Student()
	{
		std::cout << "destructure student" << std::endl;
	};
	virtual void DoSomething() const // note compiler forces us to use const
	{
		std::cout << "Student Doing Something" << std::endl;
	}
};

void test(const Person &p) // Using base class type here
{
	std::cout << "validate student" << std::endl;
	p.DoSomething(); // Output: Student Doing Something
}

int main()
{
	Student student; // Passing derived class object

	test(student);
}