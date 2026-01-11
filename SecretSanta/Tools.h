#pragma once
//helper functions
// comment from laptop
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
			cin.clear();
			cin.ignore(999, '\n');
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
		cout << prompt ;

		if (!(cin >> input)) // checks for 
		{
			cout << "error: invlid input" << endl;
			cin.clear();
			cin.ignore(999, '\n');
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

string intputString(string prompt)
{
	bool badInput = true;
	string input;
	do // does once then checks if statment is still true
	{
		cout << prompt;
		if (!(cin >> input)) // checks for 
		{
			cout << "error: invlid input" << endl;
		}
		else
		{
			badInput = false;
		}
	} while (badInput);

	return input;
}

bool inputBool()
{
	char input;
	bool badInput = true;
	do
	{
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input" << endl;
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (toupper(input) == 'Y')
		{
			cin.clear();
			cin.ignore(999, '\n');
			return true;
		}
		else if (toupper(input) == 'N')
		{
			cin.clear();
			cin.ignore(999, '\n');
			return false;
		}
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "CHARACTER ERROR: Enter Y (Yes) or N (No): " ;
		}
		

	} while (badInput);
}