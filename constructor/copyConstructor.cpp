#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
public:
	String() = default;
	explicit String(const char *string)
	{
		printf("String CTOR\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String &other)
	{
		printf("String Copy CTOR\n");
		// Deep copy - Clone data from memory address to another memory address
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String &&other) noexcept
	{
		printf("String Move CTOR\n");
		// Shallow copy - Point to other's data's addresses
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		// Move other's data's addresses - Ensure when the passed rvalue (temporary object) is destructured it won't affect this object's data
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String &operator=(const String &other) noexcept
	{
		printf("String Copy Operator\n");

		if (this == &other)
		{
			printf("Early return form String Copy Operator\n");
			return *this;
		}

		delete[] m_Data;

		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);

		return *this;
	}

	~String()
	{
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}

private:
	char *m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	// This name that is lvalue or rvalue (in this case only lvalue as we have the below CTOR handle the rvalue case which takes precedence)
	explicit Entity(const String &name) : m_Name(name)
	{
		printf("Entity CTOR\n");
	}

	// Take care of name is rvalue case as it takes precedence than the above ctor
	// String&& and std::move to ensure it calls String class's MOVE ctor
	Entity(String &&name) : m_Name(std::move(name))
	{
		printf("Entity CTOR that takes String as rvalue reference\n");
	}

	Entity(const Entity &other)
	{
		printf("Entity Copy CTOR\n");
		// Deep copy - Clone data from memory address to another memory address
		m_Name = String("asd");
	}

	Entity &operator=(const Entity &other) noexcept
	{
		printf("Entity Copy Operator\n");

		if (this == &other)
		{
			printf("Early return form Entity Copy Operator\n");
			return *this;
		}

		m_Name = other.m_Name;

		return *this;
	}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};

void test(int &&number)
{
	cout << number;
}

int main()
{
	// str is lvalue
	String name = String("Cherno");
	Entity *entity;
	Entity e1(name);
	Entity e2(name);
	e1 = e2;
};

// String CTOR
// String Copy CTOR
// Entity CTOR
// String Copy CTOR
// Entity CTOR
// Entity Copy Operator
// String Copy Operator
