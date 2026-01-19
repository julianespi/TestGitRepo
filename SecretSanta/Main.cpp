//Julian Espinzoa
// main menu file
// comment from laptop
#include <iostream>
#include <vector>
#include "Person.h"
#include "Tools.h"

using namespace std;

void startUp(vector<person> &partcipants);
void excludingAPerson(vector<person>& availableExcludedPersons, vector<person>& partcipants, int i);
void excludingPersons(vector<person>& availableExcludedPersons, vector<person>& partcipants, int i);
void disaplayPersonAsChoices(vector<person> availableExcludedPersons, string optionWord);

int main()
{

    vector<person> partcipants;
    int option;

    cout << "secret santa picker" << endl;
    cout << "=====================" << endl;
    cout << "1. start up" << endl;
    cout << "2. add participant" << endl;
    cout << "3. remove participant" << endl;
    cout << "4. edit want" << endl;
    cout << "5. edit exluded names" << endl;
    cout << "6. exit" << endl;
    cout << "======================" << endl;

    option = inputNumberRange(1, 6);

    switch (option)
    {
    case 1:
    {
        startUp(partcipants);
    }
    case 2:
    {

    }
    case 3:
    {

    }
    case 4:
    {

    }
    case 5:
    {

    }
    case 6:
    {
        return 0;
    }
    default:
    {
        break;
    }
    }

    //cout << option;
}
//this would be passing by pointer and then have to be dereferenced 
//void startUp(vector<person> *partcipants)


//this is passing by reference this allows for direct editing of the original variable without needing to dereference
void startUp(vector<person> &partcipants) 
{
    int numberOfParticipants = inputNumber("select a number of particpants: "); // i get a loop if i dont enter a number

    partcipants.resize(numberOfParticipants);

	//Gets names of participants
	cout << "Enter the participants names: " << endl;

    for(int i = 0; i < numberOfParticipants; i++)
    {
        partcipants[i].setName(intputString("name: "));
    }

	//gets the excluded names for each participant by looping from person to person
    for(int i = 0; i < numberOfParticipants; i++)
    {
        bool firstTime = false;

        // displays the current individual and ask if it is there first time
        cout << "for " << partcipants[i].getName() << " is it there first time: " ;

        // this loops copies all but the currnet user into a temp vector except for the one choosing who from the group 
        // to exlude
        vector<person> availableExcludedPersons;
        for (int j = 0; j < numberOfParticipants; j++)
        {
            if (j != i)
            {
                availableExcludedPersons.push_back(partcipants[j]);
            }
        }

        if (firstTime = inputBool())// gets the firstTime boolean answer. This asumes the person is participating for the first time
        {
            // this function exludes people based on choice
            excludingPersons(availableExcludedPersons, partcipants, i);
        }
        else // this is for people particpating again this year.
        {
            //ask the person who they got last year
            cout << "Who did you get last year: " << endl;
            disaplayPersonAsChoices(availableExcludedPersons,"No one");
            excludingAPerson(availableExcludedPersons, partcipants, i);

            excludingPersons(availableExcludedPersons, partcipants, i);

        }
	}
    cout << "everyone was entered and everyone picked who they wanted to not get " << endl;
}

void excludingAPerson(vector<person>& availableExcludedPersons, vector<person>& partcipants, int i)
{
    int exlucedIndex = inputNumberRange(1, availableExcludedPersons.size() + 1);

    if (exlucedIndex == (availableExcludedPersons.size() + 1)) //exit option
    {
        if (partcipants[i].getExludedNameSize() == 0)
        {
            cout << "You picked to exlude no one" << endl << endl;
            return;
        }
        else
        {
            cout << partcipants[i].getName() << " picked to exlude the following: " << endl;
            partcipants[i].getExludedNames();
        }
    }
    else
    {
        cout << partcipants[i].getName() <<" picked to exlude " << availableExcludedPersons[exlucedIndex - 1].getName() << " from your pick pool" << endl << endl;
        partcipants[i].setExludedName(availableExcludedPersons[exlucedIndex - 1].getName());
        availableExcludedPersons.erase(availableExcludedPersons.begin() + (exlucedIndex - 1));
    }
}

void excludingPersons(vector<person> &availableExcludedPersons, vector<person> &partcipants, int i)
{
    cout << "would like to pick a person that you would not want to get: "; //first propmpting of asking the user if they want to exclude someone
    bool choice = inputBool();
    int tempSize = 0;
    do
    {
        if (choice)
        {
            disaplayPersonAsChoices(availableExcludedPersons, "Done");
            tempSize = availableExcludedPersons.size(); // get the current size of the excluded names

            excludingAPerson(availableExcludedPersons, partcipants, i); // run process to see if the user wants to exluded others
            
            if (tempSize == availableExcludedPersons.size()) // checks if the temp size is the same
            {
                return;
            }
            else
            {
                //if not the same size indicats a change then ask to see if they would like to exluded another person
                cout << "would you like to pick another person to excluded: "; //second prompt to exlude someone
                choice = inputBool();
            }
        }
    } while (choice);
}

void disaplayPersonAsChoices(vector<person> availableExcludedPersons,string optionWord)
{
    for (int j = 0;j < availableExcludedPersons.size(); j++) // this loops displays the persons that we would could exlude
    {
        cout << "\t[" << j + 1 << "] " << availableExcludedPersons[j].getName() << endl;
    }
    cout << "\t[" << availableExcludedPersons.size() + 1 << "] "<< optionWord << endl;
}



