// comparing apples with apples
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

bool isNumber(const string &str)
{
	char *pEnd;
	strtod(str.c_str(), &pEnd);

	return *pEnd == 0;
}

vector<string> split(const string str)
{
	stringstream ss(str);
	vector<string> result;
	string word;

	while (ss >> word)
	{
		result.push_back(word);
	}

	return result;
}

void validateOperands(const vector<string> splittedStr)
{
	if (splittedStr[0].empty() || !isNumber(splittedStr[0]))
	{
		cout << "Error: Left hand side operand must be a number";
		exit(EXIT_FAILURE);
	}

	if (splittedStr[2].empty() || !isNumber(splittedStr[2]))
	{
		cout << "Error: Left hand side operand must be a number";
		exit(EXIT_FAILURE);
	}
}

void validateOperator(const vector<string> splittedStr)
{
	size_t found = splittedStr[1].find_first_not_of("+-*/");
	if (found != string::npos)
	{
		cout << "Error: Operator must be a +, -, *, /";
		exit(EXIT_FAILURE);
	}
}

void calculator(const vector<string> splittedStr)
{
	size_t result;

	const char *optrCharArr = splittedStr[1].c_str();
	char optr = optrCharArr[0];
	size_t leftOperand = atoi(splittedStr[0].c_str());
	size_t rightOperand = atoi(splittedStr[2].c_str());

	switch (optr)
	{
	case '+':
		result = leftOperand + rightOperand;
		break;

	case '-':
		result = leftOperand - rightOperand;
		break;

	case '*':
		result = leftOperand * rightOperand;
		break;

	case '/':
		result = leftOperand / rightOperand;
		break;

	default:
		result = 0;
		break;
	}

	printf("Answer of %zu %c %zu = %zu\n\n", leftOperand, optr, rightOperand, result);
}

int main()
{
	string calculation;
	int operand1, operand2;

	while (true)
	{
		cout << "Calculation: ";
		getline(cin, calculation);

		vector<string> splittedStr = split(calculation);
		validateOperands(splittedStr);
		validateOperator(splittedStr);

		calculator(splittedStr);
	}

	return 0;
}