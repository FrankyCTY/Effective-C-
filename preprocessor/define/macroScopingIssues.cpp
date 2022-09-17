#include <stdio.h>

void funcOne()
{
#define MY_VAL 1
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
}

void funcTwo()
{
#define MY_VAL 999
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
}

int main()
{
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
	funcOne();
	funcTwo();
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
	return 0;
}

// ========== Output ==========
// main: 999
// funcOne: 1
// funcTwo: 999
// main: 999

#include <stdio.h>

void funcOne()
{
#define MY_VAL 1
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
}

int main()
{
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
	funcOne();
	funcTwo();
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
	return 0;
}

void funcTwo()
{
#define MY_VAL 999
	printf("%s: %d\r\n", __FUNCTION__, MY_VAL);
}

// ========== Output ==========
// main: 1
// funcOne: 1
// funcTwo: 999
// main: 1