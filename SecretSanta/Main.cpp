//Julian Espinzoa
// main menu file
// comment from laptop
#include <iostream>
#include <vector>
#include "Person.h"
#include "Tools.h"

using namespace std;

void startUp(vector<person>* partcipants);

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
        startUp(&partcipants);
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

void startUp(vector<person>* partcipants) // I should pass this in by refrence so that it does not make a copy
{
    int numberOfParticipants = inputNumber("select  a number of particpants ");

    for (int i = 0; i < numberOfParticipants; i++)
    {
        //partci
    }
}


