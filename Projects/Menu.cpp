#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

//Constructor
Menu::Menu() {
	ReaderWriter rw;
	string filename = "newloc.txt";
	locT = rw.createTreeFromFile(filename);
	//int choice = -1;
}

void Menu::menuOptions(int &choice) {

    do {
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl;

    cout << "\tMain Menu - Choose an Option below:" << endl << endl;

    cout << "\t1. Add Record" << endl;
    cout << "\t2. Administer Record" << endl;
    cout << "\t3. Find Distance" << endl << endl;
	cout << "\t4. Quit" << endl << endl;

    cout << "\tChoose an Option: ";
    cin >> choice;


        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                administerRecord();
                break;
            case 3:
                cout << "Find Distance";
                break;
            case 4:
                cout << "Quit";
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << endl << "Invalid Choice" <<endl << endl;
                break;
        }
    } while (choice != 4);
}

void Menu::addRecord() {

	Location *newLoc;
	string city;
	string country;
	string region;
	int latDeg;
	int latMin;
	string latDir;
	int lonDeg;
	int lonMin;
	string lonDir;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

    cout << "\tAdd Record" << endl << endl;

	cout << "\tEnter City: "; cin >> city;
	cout << "\tEnter Country: "; cin >> country;
	cout << "\tEnter Region: "; cin >> region;
	cout << "\tEnter Latitude Degrees: "; cin >> latDeg;
	cout << "\tEnter Latitude Minutes: "; cin >> latMin;
	cout << "\tEnter Latitude Direction: "; cin >> latDir;
	cout << "\tEnter Longitude Degrees: "; cin >> lonDeg;
	cout << "\tEnter Longitude Minutes: "; cin >> lonMin;
	cout << "\tEnter Longitude Direction: "; cin >> lonDir;


	newLoc = new Location(city, country, region, latDeg, latMin, latDir,
				lonDeg, lonMin, lonDir);
		locT->addNode(newLoc);

	cout << endl;
}

void Menu::administerRecord() {

    int choice;
    char city[10];

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

	cout << "\tAdminister Record - Find by:" << endl << endl;

	cout << "\t1. City" << endl;
    cout << "\t2. Country" << endl;
	cout << "\t3. Region" << endl;
	cout << "\t4. Show All" << endl;
    cout << "\t5. Quit to Main Menu" << endl;

    cout << endl << "\tChoose an Option: ";
    cin >> choice;

    do {
        switch(choice){
            case 1:
                cout << "Enter City Name: "; cin >> city;
                cout << endl << "Cities found matching "; city;
            }
    } while (choice != 5);

}

void Menu::findDistance() {
	string cityOne;
	string cityTwo;
	cout << "Enter the first City's Name: "; cin >> cityOne;
	cout << "Enter the second City's Name: "; cin >> cityTwo;
}



