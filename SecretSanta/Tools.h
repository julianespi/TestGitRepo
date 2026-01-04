#pragma once
//helper functions
#include <iostream>
using namespace std;

int inputNumberRange(int lowerRange, int upperRange)
{
	bool badInput = true;
	int input;
	do // does once then checks if statment is still true
	{
		cout << "Enter a number between " << lowerRange << " and " << upperRange << ": ";

		if (!(cin >> input)) // checks for 
		{
			cout << "error: invlid input" << endl;
		}
		else if (isalpha(input)) // check if it is a letter
		{
			cout << "character error: enter a number not a letter " << endl;
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (input > upperRange || input < lowerRange) // checks the upper and lower limits of a number
		{
			cout << "range error: input is out of bounds" << endl;
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			badInput = false;
		}

	} while (badInput);


	return input;
}

int inputNumber(string prompt)
{
	bool badInput = true;
	int input;
	do // does once then checks if statment is still true
	{
		cout << prompt << endl;

		if (!(cin >> input)) // checks for 
		{
			cout << "error: invlid input" << endl;
		}
		else if (isalpha(input)) // check if it is a letter
		{
			cout << "character error: enter a number not a letter " << endl;
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			badInput = false;
		}

	} while (badInput);


	return input;
}