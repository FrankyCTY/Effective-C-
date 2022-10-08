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
		// If start and end points to the same address block, it will return 0, so we need to add 1
		int totalAddressBlocks = end - start + 1;
		int newSize = size + 1;
		bool requireResize = totalAddressBlocks < newSize;

		if (requireResize)
		{
			int newTotalAddressBlocks = totalAddressBlocks * 2;
			int *temp = (int *)realloc(start, newTotalAddressBlocks * sizeof(int));
			if (temp == nullptr)
			{
				cout << "Memory not allocated" << endl;
				exit(EXIT_SUCCESS);
			}

			start = temp;
			end = getEndingMemoryBlockAddress(newTotalAddressBlocks);
			temp = nullptr;
			free(temp);

			resizedAmount++;
		}

		int newMemoryBlockIdx = newSize - 1;
		*(start + newMemoryBlockIdx) = x;
		size++;
	}

	int *getEndingMemoryBlockAddress(int &totalAddressBlocks)
	{
		return start + (totalAddressBlocks - 1);
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
	list.insert(2);
	list.insert(2);

	// ========= List should resize from 4 to 8 for the insert in next line ==========
	list.insert(2);
	list.insert(2);
	list.insert(2);
	list.insert(2);

	// ========== List should resize from 8 to 16 for the insert in next line ==========
	list.insert(2);

	list.printList();
	cout << "Resized time = " << list.resizedAmount << endl;
	return 0;
}
