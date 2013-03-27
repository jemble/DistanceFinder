#ifndef Menu_H
#define Menu_H

#include "Location.h"
#include "Node.h"
#include "LocationTree.h"
#include "ReaderWriter.h"

using namespace std;

class Menu {
public:
	//Constructor
	Menu();

	LocationTree* locT;

	//Function Prototypes
    void menuOptions(int &choice);
    void addRecord();
    void administerRecord();
	void findDistance();


};

#endif
