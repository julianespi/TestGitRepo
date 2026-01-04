#pragma once //tells the compliere to include a header file once in a single coimpliation 
//person class
// comment from laptop
#include <iostream>
#include <vector>
using namespace std;
class person
{
private: // keeps values from being edited directily 
	string name;
	vector<string> excludedNames;
	vector<string> wants;
public: // allows for the setting and getting of the private variables and constructors 

	// constructor 
	person()
	{
		name = "";
		excludedNames = {}; // This is the syntax to make an empty vector
		wants = {};
	}

	// copy constructor
	person(string newName, vector<string> newExcludedNames, vector<string> newWants)
	{
		name = newName;
		for (int i = 0; i < newExcludedNames.size(); i++)
		{
			excludedNames[i] = newExcludedNames[i];
		}

		for (int i = 0; i < newWants.size(); i++)
		{
			wants[i] = newWants[i];
		}
	}

	//setters
	void setName(string newName)
	{
		name = newName;
	}

	void setExludedNames(vector<string> newExludedNames)
	{
		for (int i = 0; i < newExludedNames.size(); i++)
		{
			excludedNames[i] = newExludedNames[i];
		}
	}

	void setWants(vector<string> newWants)
	{
		for (int i = 0; i < newWants.size(); i++)
		{
			wants[i] = newWants[i];
		}
	}

	//getters
	string getName()
	{
		return name;
	}

	string getExludedName(int i)
	{
		return excludedNames[i];
	}

	string getWant(int i)
	{
		return wants[i];
	}

	//functions
	void addExludedName(string name)
	{
		excludedNames.push_back(name);
	}
};


