// Soomin Lee 040899389 CST8219 303
#include "Car.h"

CST8219::Car::Car(int w, int d) {			//constrcutor for the number of wheels and doors
	numWheels = w;
	numDoors = d;

	cout << "In constructor with 2 parameters" << endl;
}
CST8219::Car::Car(int w) : Car(w, 4) { 	//constructor with parameter doors = 4
	cout << "In constructor with 1 parameters, wheels= " << w << endl;
}
CST8219::Car::Car() : Car(4) {	//empty constructor, calling another constructor
	cout << "In constructor with 0 parameters" << endl;
}

// --------------------week4------------------------
void CST8219::Car::printVehicle(void) {
	cout << "week4 : number of wheels:" << getWheels() << endl;
	cout << "week4 : number of doors:" << getDoors() << endl;
	cout << "------------" << endl;
}

CST8219::Car::Car(Car& copy) :Car(&copy) {			// pass by reference
	cout << "pass by reference" << endl;
}

CST8219::Car::Car(Car* copy) {	// pass by pointer
	cout << "pass by pointer" << endl;
	setWheels(copy->getWheels());
	setDoors(copy->getDoors());
}

CST8219::Car::~Car() {
	cout << "In destructor" << endl;
} //destructor





