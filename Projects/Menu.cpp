#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

//Constructor
Menu::Menu() {
	ReaderWriter rw;
	string filename = "locations.txt";
	locT = rw.createTreeFromFile(filename);
	//int choice = -1;
}

void Menu::menuOptions(int &choice) {

    do {
    cout << endl << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl;

    cout << endl << "Main Menu - Choose an Option below:" << endl << endl;

	cout << "1. Add Record" << endl;
	cout << "2. Administer Record" << endl;
	cout << "3. Find Distance" << endl << endl;
	cout << "4. Quit" << endl << endl;

	cout << "Choose an Option: ";
    cin >> choice;


        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                administerRecord();
                break;
            case 3:
                findDistance();
                break;
            case 4:
                cout << "Quit"; // PLACEHOLDER - REMOVE
                exit(EXIT_SUCCESS);
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

	cout << "Add Record" << endl << endl;

	cout << "Enter City: "; cin >> city;
	cout << "Enter Country: "; cin >> country;
	cout << "Enter Region: "; cin >> region;
	cout << "Enter Latitude Degrees: "; cin >> latDeg;
	cout << "Enter Latitude Minutes: "; cin >> latMin;
	cout << "Enter Latitude Direction: "; cin >> latDir;
	cout << "Enter Longitude Degrees: "; cin >> lonDeg;
	cout << "Enter Longitude Minutes: "; cin >> lonMin;
	cout << "Enter Longitude Direction: "; cin >> lonDir;


	newLoc = new Location(city, country, region, latDeg, latMin, latDir,
				lonDeg, lonMin, lonDir);
		locT->addNode(newLoc);

	cout << endl;
}

void Menu::administerRecord() {

	int choice;
	string city;
	string strTemp;
	int intTemp;
	Node* rootNode;
	Node* foundNode;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

	cout << "Administer Record:" << endl << endl;

	/*cout << "\t1. City" << endl;
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
   */
		cout << "Enter City Name: "; cin >> city;
		rootNode = locT->getRoot();
		foundNode = locT->getCity(rootNode, city);
		if (foundNode == NULL) {
			cout << endl << "This city is not in the database." << endl;
			system("PAUSE"); // TESTING - REMOVE
			Menu::menuOptions(choice);
		}
		else {
			cout << endl << "Cities found matching : " << foundNode->location->getCityName()  << endl;
			cout << "In Country: " << foundNode->location->getCountryName() << endl; // TESTING!
			cout << "In Region: " << foundNode->location->getRegion() << endl; // DITTO
			cout << "Latitude Degrees: " << foundNode->location->getLatDeg() << endl; // DITTO
			cout << "Latitude Minutes: " << foundNode->location->getLatMin() << endl; // DITTO
			cout << "Longitude Degrees: " << foundNode->location->getLonDeg() << endl; // DITTO
			cout << "Longitude Minutes: " << foundNode->location->getLonMin() << endl; // DITTO
			system("PAUSE");

			cout << endl << "Do you want to Modify or Delete a record?";
			cout << endl << "1. Modify" << endl;
			cout << "2. Delete" << endl << endl;
			cout << "3. Quit to Main Menu" << endl << endl;

			cout << "Modify/Delete a Record - Choose an option: ";
			cin >> choice;

			switch(choice){
				case 1:
					cout << endl << "Enter Country: "; cin >> strTemp; foundNode->location->setCountryName(strTemp);
					cout << "Enter Region: "; cin >> strTemp; foundNode->location->setRegion(strTemp);
					cout << "Enter Latitude Degrees: "; cin >> intTemp; foundNode->location->setLatDeg(intTemp);
					cout << "Enter Latitude Minutes: "; cin >> intTemp; foundNode->location->setLatMin(intTemp);
					cout << "Enter Latitude Direction: "; cin >> strTemp; foundNode->location->setLatDirection(strTemp);
					cout << "Enter Longitude Degrees: "; cin >> intTemp; foundNode->location->setLonDeg(intTemp);
					cout << "Enter Longitude Minutes: "; cin >> intTemp; foundNode->location->setLonMin(intTemp);
					cout << "Enter Longitude Direction: "; cin >> strTemp; foundNode->location->setLonDirection(strTemp);
					break;
				case 2:
					cout << endl << "UNDER CONSTRUCTION!!!" << endl << endl; // PLACEHOLDER TEXT
					cout << "Enter City to be deleted: "; cin >> city;
					if (locT->deleteNode(city)) {
						cout << "City has been removed" << endl;
					} else {
						cout << "WARNING! Deletion unsuccessful" << endl;
                    }
					//system("PAUSE"); // TESTING - REMOVE
					Menu::menuOptions(choice);
				case 3:
					Menu::menuOptions(choice);
			}
		 }
}

void Menu::findDistance() {
	string cityOne;
	string cityTwo;
	cout << "Enter the first City's Name: "; cin >> cityOne;
	cout << "Enter the second City's Name: "; cin >> cityTwo;

	Node* rootNode = locT->getRoot();
	Node* foundNodeOne = locT->getCity(rootNode, cityOne);
	Node* foundNodeTwo = locT->getCity(rootNode,cityTwo);
	Location* locOne = foundNodeOne->location;
	Location* locTwo = foundNodeTwo->location;

	Calculator calc;
	double dist = calc.getDistanceBetween(locOne,locTwo);
	cout << "distance between is " << dist << "km" << endl;
}



