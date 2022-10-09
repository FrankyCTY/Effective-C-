#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyList
{
public:
	void insert(const int &x)
	{
		if (start == nullptr)
		{
			insertFirstElement(x);
			return;
		}

		insertSubsequentElement(x);
	}

	void printList() const
	{
		cout << "Print List with " << size << " elements" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << *(start + i) << endl;
		}
	}

private:
	void insertFirstElement(const int &x)
	{
		cout << "insert: start is a null pointer, ready to allocate dynamic memory for int" << endl;
		;
		start = (int *)malloc(sizeof(int));
		if (start == nullptr)
		{
			cout << "Memory not allocated" << endl;
			exit(0);
		}

		*start = x;
		size = 1;
		end = start;
	}

	void insertSubsequentElement(const int &x)
	{
		int *temp;
		temp = (int *)realloc(start, (size + 1) * sizeof(int));
		if (temp == nullptr)
		{
			cout << "Memory not allocated" << endl;
			exit(0);
		}
		start = temp;

		temp = nullptr;
		free(temp);

		end = start + size;
		*end = x;
		size++;
	}

private:
	int *start = nullptr;
	int *end = nullptr;
	int size;
};

int main()
{
	MyList list{};
	list.insert(1);
	list.insert(2);
	list.insert(2);
	list.insert(2);
	list.insert(2);
	list.insert(2);
	list.insert(2);

	list.printList();

	return 0;
}
