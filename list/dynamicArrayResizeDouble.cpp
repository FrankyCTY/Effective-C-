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
	int resizedAmount;

private:
	void insertFirstElement(const int &x)
	{
		cout << "insert: start is a null pointer, ready to allocate dynamic memory for int" << endl;
		;
		start = (int *)malloc(sizeof(int));
		if (start == nullptr)
		{
			cout << "Memory not allocated" << endl;
			exit(EXIT_SUCCESS);
		}

		*start = x;
		size = 1;
		end = start;
	}

	void insertSubsequentElement(const int &x)
	{
		// end - start returns the amount of blocks between end and start memory block, which should be at least 1 at this point
		int totalAddressBlocks = end - start + 1;
		int newSize = size + 1;
		bool requireResize = totalAddressBlocks < newSize;

		if (requireResize)
		{
			int newTotalAddressBlocks = totalAddressBlocks * 2;
			int *newStart = (int *)realloc(start, newTotalAddressBlocks * sizeof(int));
			if (newStart == nullptr)
			{
				cout << "Memory not allocated" << endl;
				exit(EXIT_SUCCESS);
			}

			start = newStart;
			newStart = nullptr;

			// total address blocks = 10, which mean end is 9 blocks away from the start, that's why we minus 1 hsre
			end = start + (newTotalAddressBlocks - 1);

			resizedAmount++;
		}

		// insert data
		*(start + size) = x;
		size++;
	}

private:
	int *start = nullptr;
	int *end = nullptr;
	int size = 0;
};

int main()
{
	MyList list{};
	list.insert(1);

	// ========== List should resize from 1 to 2 for the insert in next line ==========
	list.insert(2);

	// ========== List should resize from 2 to 4 for the insert in next line ==========
	list.insert(3);
	list.insert(4);

	// ========= List should resize from 4 to 8 for the insert in next line ==========
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);

	// ========== List should resize from 8 to 16 for the insert in next line ==========
	list.insert(9);

	list.printList();
	cout << "Resized time = " << list.resizedAmount << endl;
	return 0;
}

// insert: start is a null pointer, ready to allocate dynamic memory for int
// Print List with 9 elements
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// Resized time = 4