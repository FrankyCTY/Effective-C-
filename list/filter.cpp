#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book
{
	string id;
	string author;
	string title;
	bool isAvailable;
};

class Manager
{
public:
	Manager(vector<Book> *books) : m_books(books)
	{
	}

	void AddBook(const Book newBook)
	{
		m_books->emplace_back(newBook);
	}

	void printTotalNumOfBooks() const
	{
		cout << "Total number of books: " << m_books->size() << endl;
	}

	void printBookForAuthor(const string &author)
	{
		vector<Book> filteredBooks;

		// FIlter by author
		copy_if(m_books->begin(), m_books->end(), back_inserter(filteredBooks), [&author](Book b)
						{ return b.author.compare(author) == 0; });

		vector<Book>::iterator it;
		cout << "===" << endl;
		for (it = filteredBooks.begin(); it < filteredBooks.end(); it++)
		{
			cout << "Title: " << (*it).title << endl;
		}
	}

private:
	vector<Book> *m_books;
};

int main()
{
	vector<Book> *books = new vector<Book>();
	unique_ptr<Manager> manager = make_unique<Manager>(books);

	Book b{"123", "TAK", "The good book", true};
	manager->AddBook(b);
	manager->AddBook({"999", "YO MAN", "The bad book", true});

	manager->printBookForAuthor("YO MAN");

	return 0;
}
