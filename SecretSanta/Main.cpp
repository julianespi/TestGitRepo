//Julian Espinzoa
// main menu file
// comment from laptop
#include <iostream>
#include <vector>
#include "Person.h"
#include "Tools.h"

using namespace std;

void startUp(vector<person> &partcipants);

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
    int numberOfParticipants = inputNumber("select  a number of particpants: "); // i get a loop if i dont enter a number

    partcipants.resize(numberOfParticipants);

	//Gets names of participants
	cout << "Enter the participants names: " << endl;

    for(int i = 0; i < numberOfParticipants; i++)
    {
        partcipants[i].setName(intputString("name: "));
    }

	//gets the excluded names for each participant
    for(int i = 0; i < numberOfParticipants; i++)
    {   
		bool pickAnother = false;
        bool firstTime = false;
        // displays the current individual and ask if it is there first time
        cout << "for " << partcipants[i].getName() << " is it there first time: " ;
        if (firstTime = inputBool())// gets the firstTime boolean answer
        {
            vector<person> availableExcludedPersons;
            do
            {

                cout << "would like to pick a person that you would not want to get" << endl;
                if (inputBool)
                {
                    for (int j = 0; j < numberOfParticipants; j++)// this loops copies all but the currnet user
                    {
                        if (j != i)
                        {
                            availableExcludedPersons.push_back(partcipants[j]);
                        }
                        
                    }

                    for (int j = 0;j < availableExcludedPersons.size(); j++) // this loops displays the persons that we would could exlude
                    {
                        cout << "\t[" << j + 1 << "] " << availableExcludedPersons[j].getName() << endl;
                    }
                    cout << "\t[" << availableExcludedPersons.size() + 1 << "] None" << endl; // provides the skip option
                    
                    //need to add a part where the user pick a person from the avaluiable exluded person and 
                    //then adds that to the exluded names in there class

                    cout << "would you like to pick another person to excluded: ";
                    pickAnother = inputBool();

                }
            } while (pickAnother);
        }



	}

}


