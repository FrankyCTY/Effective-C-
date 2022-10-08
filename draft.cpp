#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
	Node(const int &data) : m_data(data)
	{
	}

	int getData() const
	{
		return m_data;
	}

	Node *getNext() const
	{
		return m_next;
	}

	void setNext(Node *next)
	{
		m_next = next;
	}

private:
	Node *m_next = nullptr;
	int m_data;
};

class Linkedlist
{
public:
	void insert(const int &x)
	{
		if (startNode == nullptr)
		{
			Node *node = new Node(x);
			startNode = node;
			endNode = node;
			size++;
			return;
		}

		Node *node = new Node(x);
		endNode->setNext(node);
		endNode = node;
		size++;
	}

	void printList()
	{
		Node *ptr = startNode;
		while (ptr != nullptr)
		{
			cout << ptr->getData() << endl;
			ptr = ptr->getNext();
		}
	}

private:
	Node *startNode = nullptr;
	Node *endNode = nullptr;
	int size = 0;
};

int main()
{
	Linkedlist linkedList;
	linkedList.insert(1);

	// ========== List should resize from 1 to 2 for the insert in next line ==========
	linkedList.insert(2);

	// ========== List should resize from 2 to 4 for the insert in next line ==========
	linkedList.insert(2);
	linkedList.insert(2);

	// ========= List should resize from 4 to 8 for the insert in next line ==========
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(2);

	// ========== List should resize from 8 to 16 for the insert in next line ==========
	linkedList.insert(2);

	linkedList.printList();
	return 0;

	return 0;
}
