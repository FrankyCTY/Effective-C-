#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aggregate
{
public:
	virtual void Add(string newItem) = 0;
	virtual string GetItem(int position) const = 0;
	virtual int GetSize() const = 0;
};

class Iterator
{
public:
	Iterator(Aggregate *wordsAggregate) : _position(0), _wordsAggregate(wordsAggregate){};

	int GetElementPosition() const
	{
		return _position;
	}

	void SetElementPosition(int newPosition)
	{
		bool isInvalidPosition = newPosition > _wordsAggregate->GetSize() - 1;
		if (isInvalidPosition)
		{
			printf("Invalid new position %d\n", newPosition);
			return;
		}

		_position = newPosition;
	}

	// Get current element
	string Current()
	{
		return _wordsAggregate->GetItem(GetElementPosition());
	}

	void Next()
	{
		_position++;
	}

	bool isTraversalDone()
	{
		int totalWords = _wordsAggregate->GetSize();
		return _position > totalWords - 1;
	}

private:
	int _position;
	Aggregate *_wordsAggregate;
};

class WordsAggregate : public Aggregate
{
public:
	WordsAggregate() : _size(0){};

	void Add(string newWork)
	{
		_words.push_back(newWork);
		_size++;
	};

	string GetItem(int position) const
	{
		return _words[position];
	}

	int GetSize() const
	{
		return _size;
	}

	Iterator *CreateIterator()
	{
		return new Iterator(this);
	}

private:
	int _size;
	vector<string> _words;
};

int main()
{
	WordsAggregate *aggregate = new WordsAggregate();
	aggregate->Add("hello");
	aggregate->Add("world");

	Iterator *it = aggregate->CreateIterator();
	cout << "Current position " << it->GetElementPosition() << endl;
	cout << "Current element " << it->Current() << endl;
	cout << "Is Traversal Finished: " << it->isTraversalDone() << "\n"
			 << endl;

	cout << "=========== Traversal Start ===========\n"
			 << endl;

	it->SetElementPosition(100);
	for (it->GetElementPosition(); !it->isTraversalDone(); it->Next())
	{
		cout << it->GetElementPosition() << " " << it->Current() << endl;
	}

	return 0;
};

// Current position 0
// Current element hello
// Is Traversal Finished : 0
//
// =========== Traversal Start ===========
//
// Invalid new position 100
// 0 hello
// 1 world
