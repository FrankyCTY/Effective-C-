// comparing apples with apples
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Test t;
	// t.x = 50;
	// cout << t.y;
	char arr[] = {'a', 'b', 'c', 'd', 'e'};

	// type casting array's address to char* so that we can type cast to int*
	// Then plus 1 size of int (etc. 4 bytes)
	int *ptr = (int *)((char *)&arr) + 1;

	// Should print out e - Because each char occupies 1 byte, according to comment on line 29, we compiler will checkout
	// the data in 4 bytes after the first char, which should return the address of the fifth char
	cout << ptr << " " << (char)*ptr << endl;

	return 0;
}