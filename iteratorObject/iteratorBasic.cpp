#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WordsAggregate
{

public:
	void Add(string newWork)
	{
		_words.push_back(newWork);
	};

	void PrintAllWords()
	{
		vector<string>::iterator it = _words.begin();

		for (it; it != _words.end(); ++it)
		{
			cout << *it << ' ';
		}
	}

private:
	vector<string> _words;
};

int main()
{
	WordsAggregate *aggregate = new WordsAggregate();
	aggregate->Add("hello");
	aggregate->Add("world");

	aggregate->PrintAllWords();

	delete aggregate;
	return 0;
};

// hello world
