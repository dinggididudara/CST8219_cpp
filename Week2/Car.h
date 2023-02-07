// Soomin Lee 040899389 CST8219 303
#pragma once
#include<iostream>

using namespace std;

namespace CST8219 {
	class Car {
	private:
		int numWheels, numDoors;

	public:
		Car(int w, int d);
		Car(int w);
		Car();

		void printVehicle(void);

		Car(Car&);		// copy by reference	
		Car(Car*);		// copy by pointer

		void setWheels(int w) { numWheels = w; }
		int getWheels(void) { return numWheels; }

		void setDoors(int d) { numDoors = d; }
		int getDoors(void) { return numDoors; }
				
		~Car();
	}; //class end
} //CST8219 end


