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

		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);

		return *this;
	}

	String &operator=(String &&other) noexcept
	{
		printf("String Move Operator\n");

		// Don't delete data in memory and move data if this and other have the same memory address
		// Otherwise it will cause unexpected data removal in the adderss
		if (this == &other)
			return *this;

		printf("MOVED\n");

		// As we are explicitly changing pointer, we need to remove the old data in that memory address ourself (can't rely on destructor)
		delete[] this->m_Data;

		this->m_Size = other.m_Size;
		this->m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;

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

int main()
{
	String str1 = String("hello");
	String str2 = String("a");

	str2 = move(str1);

	str1.Print();
	str2.Print();

	return 0;
};

// String CTOR
// String CTOR
// String Copy Operator
// MOVED
//
// hello