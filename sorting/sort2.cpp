#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Comparison logic in the nested loop
// i and j are used for counting how many times we need to compare
// Values are sorted by moving opposite to the back
void sort(int arr[], int length, bool (*compare)(const int &, const int &))
{
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		int amountOfComparisons = length - i - 1;
		for (j = 0; j < amountOfComparisons; j++)
		{
			if (!compare(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
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