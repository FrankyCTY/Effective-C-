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

	void setData(int data)
	{
		m_data = data;
	}

	Node *getNext() const
	{
		return m_next;
	}

	void setNext(Node *next)
	{
		m_next = next;
	}

	Node &operator=(const int &data)
	{
		m_data = data;
		return *this;
	}

	friend ostream &operator<<(ostream &out, const Node &node)
	{
		out << node.getData();
		return out;
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
		if (head == nullptr)
		{
			Node *node = new Node(x);
			head = node;
			tail = node;
			m_size++;
			return;
		}

		Node *node = new Node(x);
		tail->setNext(node);
		tail = node;
		m_size++;
	}

	void printList()
	{
		Node *ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->getData() << endl;
			ptr = ptr->getNext();
		}

		delete ptr;
	}

	void remove(const int &targetNodeIdx)
	{
		if (targetNodeIdx > m_size - 1)
		{
			cout << "Array index out of bound, exiting";
			exit(EXIT_SUCCESS);
		}
		else if (targetNodeIdx == 0)
		{
			removeHead();
		}
		else if (targetNodeIdx == m_size - 1)
		{
			removeTail();
		}
		else
		{
			Node *prevNodeOfTarget = getNode(targetNodeIdx - 1);
			Node *targetNode = getNode(targetNodeIdx);
			Node *nextNodeOfTarget = targetNode->getNext();

			prevNodeOfTarget->setNext(nextNodeOfTarget);

			delete targetNode;
			m_size--;
		}
	}

	int size() const
	{
		return m_size;
	}

	Node &operator[](int idx)
	{
		Node *iteratorPtr = head;

		if (idx > m_size - 1)
		{
			cout << "Array index out of bound, exiting";
			exit(EXIT_SUCCESS);
		}

		for (int i = 0; i < m_size; i++)
		{
			if (idx == i)
			{
				return *iteratorPtr;
			}

			iteratorPtr = iteratorPtr->getNext();
		}
	}

private:
	Node *getNode(const int &idx)
	{
		Node *iteratorPtr = head;

		if (idx > m_size - 1)
		{
			cout << "Array index out of bound, exiting";
			exit(EXIT_SUCCESS);
		}

		for (int i = 0; i < m_size; i++)
		{
			if (idx == i)
				return iteratorPtr;

			iteratorPtr = iteratorPtr->getNext();
		}
	}

	void removeHead()
	{
		Node *temp = head;
		if (head->getNext() != nullptr)
		{
			head = head->getNext();
		}

		delete temp;
		m_size--;
	}

	void removeTail()
	{
		int tailNodeIndex = m_size - 1;

		delete tail;
		tail = getNode(tailNodeIndex - 1);
		tail->setNext(nullptr);
		m_size--;
		return;
	}

private:
	Node *head = nullptr;
	Node *tail = nullptr;
	int m_size = 0;
};

int main()
{
	Linkedlist linkedList;
	linkedList.insert(1);
	linkedList.insert(2);
	linkedList.insert(99);
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(2);
	linkedList.insert(500);

	// test deleting head node
	linkedList.remove(0);

	// test deleting middle node
	linkedList.remove(2);

	// test deleting tail node
	linkedList.remove(6);

	linkedList.printList();

	cout << "Printing the third element in the linked list: " << linkedList[2] << endl;
	linkedList[2] = 120;
	cout << "Printing the third element in the linked list: " << linkedList[2] << endl;

	cout << "============== List linked list after operations ==============" << endl;
	linkedList.printList();

	cout << "Total elements: " << linkedList.size() << endl;

	return 0;
}

// 2
// 99
// 2
// 2
// 2
// 2
// Printing the third element in the linked list: 2
// Printing the third element in the linked list: 120
// ============== List linked list after operations ==============
// 2
// 99
// 120
// 2
// 2
// 2
// Total elements: 6