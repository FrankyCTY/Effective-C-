#include <iostream>
#include <string>

using namespace std;

bool isBitOne(long long x)
{
	return x & 1;
}

int main()
{
	long long x;
	cin >> x;
	string bin;

	while (x != 0)
	{
		bin += (char)isBitOne(x) ? '1' : '0';
		x >>= 1;
	}

	reverse(bin.begin(), bin.end());
	cout << bin;

	return 0;
}