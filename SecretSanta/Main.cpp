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
        int x = 4;
        int *xPtr = &x;
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
    int numberOfParticipants = inputNumber("select  a number of particpants: ");

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
        cout << "for " << partcipants[i].getName() << " who can they not get: " << endl;
        do 
        {   
            int i = 0;
            
            partcipants[i].setExludedName(intputString("Name: "));
            pickAnother = inputBool("Would you like to enter another person: ");

            i++;
        }while (pickAnother);



	}

}


