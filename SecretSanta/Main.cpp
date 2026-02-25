//Julian Espinzoa
// main menu file
// comment from laptop
#include <iostream>
#include <vector>
#include "Person.h"
#include "Tools.h"

using namespace std;

int menu();
void startUp(vector<person> &participants);
void gettingExclusions(vector<person>& participants, int i);
void excludingAPerson(vector<person>& availableExcludedPersons, vector<person>& participants, int i);
void excludingPersons(vector<person>& availableExcludedPersons, vector<person>& participants, int i);
void displayPersonAsChoices(vector<person> availableExcludedPersons, string optionWord);
void addingAPerson(vector<person>& participants);
void seeParticipants(vector<person>& participants);

int main()
{
    vector<person> participants;

    do
    {
        switch (menu())
        {
            case 0: return 0;break;
            case 1:startUp(participants);break;
            case 2:addingAPerson(participants);break;

            case 3:
            {
                cout << "option 3" << endl;
            };break;

            case 4:
            {
                cout << "option 4" << endl;
            };break;

            case 5:
            {
                cout << "option 5" << endl;
            };break;

            case 6: seeParticipants(participants);break;

            default:
            {
                cout << "Invalid option try again" << endl;
            }
        }
    } while (true);
}

int menu()
{
    cout << endl << endl;
    cout << "secret Santa picker" << endl;
    cout << "=====================" << endl;
    cout << "1. start up" << endl;
    cout << "2. add participant" << endl;
    cout << "3. remove participant" << endl;
    cout << "4. edit want" << endl;
    cout << "5. edit exluded names" << endl;
    cout << "6. view participants" << endl;
    cout << "0. exit" << endl;
    cout << "======================" << endl;
    

    int option = inputNumberRange(0, 6);
    cout << endl << endl;

    return option;
}

//this is passing by reference this allows for direct editing of the original variable without needing to dereference
void startUp(vector<person> &participants) 
{
    int numberOfParticipants = inputNumber("select a number of particpants: "); // i get a loop if i dont enter a number

    participants.resize(numberOfParticipants);

	//Gets names of participants
	cout << "Enter the participants names " << endl;

    for(int i = 0; i < numberOfParticipants; i++)
    {
        participants[i].setName(intputString("name: "));
    }

	//gets the excluded names for each participant by looping from person to person
    for(int i = 0; i < numberOfParticipants; i++)
    {
        gettingExclusions(participants, i);
	}
    cout << "everyone was entered and everyone picked who they wanted to not get " << endl;
}

void gettingExclusions(vector<person>& participants, int i)
{
    bool firstTime = false;

    // displays the current individual and ask if it is there first time
    cout << "for " << participants[i].getName() << " is it there first time: ";

    // this loops copies all but the currnet user into a temp vector except for the one choosing who from the group 
    // to exlude
    vector<person> availableExcludedPersons;
    for (int j = 0; j < participants.size(); j++)
    {
        if (j != i)
        {
            availableExcludedPersons.push_back(participants[j]);
        }
    }

    if (firstTime = inputBool())// gets the firstTime boolean answer. This asumes the person is participating for the first time
    {
        // this function exludes people based on choice
        excludingPersons(availableExcludedPersons, participants, i);
    }
    else // this is for people particpating again this year.
    {
        //ask the person who they got last year
        cout << "Who did you get last year: " << endl;
        displayPersonAsChoices(availableExcludedPersons, "No one");
        excludingAPerson(availableExcludedPersons, participants, i);

        //this is if they want to exluded other perons than the person they got last year 
        excludingPersons(availableExcludedPersons, participants, i);

    }
}

void excludingAPerson(vector<person>& availableExcludedPersons, vector<person>& participants, int i)
{
    int exlucedIndex = inputNumberRange(1, availableExcludedPersons.size() + 1);

    if (exlucedIndex == (availableExcludedPersons.size() + 1)) //exit option
    {
        if (participants[i].getExludedNameSize() == 0)
        {
            cout << "You picked to exlude no one" << endl << endl;
            return;
        }
        else
        {
            cout << participants[i].getName() << " picked to exlude the following: " << endl;
            participants[i].getExludedNames();
        }
    }
    else
    {
        cout << participants[i].getName() <<" picked to exlude " << availableExcludedPersons[exlucedIndex - 1].getName() << " from your pick pool" << endl << endl;
        participants[i].setExludedName(availableExcludedPersons[exlucedIndex - 1].getName());
        availableExcludedPersons.erase(availableExcludedPersons.begin() + (exlucedIndex - 1));
    }
}

void excludingPersons(vector<person> &availableExcludedPersons, vector<person> &participants, int i)
{
    cout << "would you like to pick a person that you would not want to get: "; //first propmpting of asking the user if they want to exclude someone
    bool choice = inputBool();
    int tempSize = 0;
    do
    {
        if (choice)
        {
            displayPersonAsChoices(availableExcludedPersons, "Done");
            tempSize = availableExcludedPersons.size(); // get the current size of the excluded names

            excludingAPerson(availableExcludedPersons, participants, i); // run process to see if the user wants to exluded others
            
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

void displayPersonAsChoices(vector<person> availableExcludedPersons,string optionWord)
{
    for (int j = 0;j < availableExcludedPersons.size(); j++) // this loops displays the persons that we would could exlude
    {
        cout << "\t[" << j + 1 << "] " << availableExcludedPersons[j].getName() << endl;
    }
    cout << "\t[" << availableExcludedPersons.size() + 1 << "] "<< optionWord << endl;
}

void addingAPerson(vector<person>& participants)
{
    person newParticipant;
    cout << "enter the name of the person you want to add: ";
    newParticipant.setName(intputString(""));

    participants.insert(participants.end(), newParticipant);

    gettingExclusions(participants, participants.size()-1);

}

void seeParticipants(vector<person>& participants)
{
    for (int i = 0; i < participants.size(); i++)
    {
        participants[i].displayPerson();
    }
}



