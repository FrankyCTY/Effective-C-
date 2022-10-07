#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Comparison logic in the for loops
// i represents main position, j represents position of comparison candidate
void sort(int arr[], int length, bool (*compare)(const int &, const int &))
{
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (!compare(arr[i], arr[j]))
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

bool asc(const int &a, const int &b)
{
	return a < b;
}

bool desc(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int arr[] = {0, 2, 5, 6, 9, 1, 3, 4, 8, 7};
	int length = sizeof(arr) / sizeof(arr[0]);

	// sort(arr, length, asc);
	sort(arr, length, desc);

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}