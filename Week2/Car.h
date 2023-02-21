// Soomin Lee 040899389 CST8219 303
#pragma once
#include <iostream>
#include <ostream>

using namespace std;

namespace CST8219 {
	class Car {
	private:
		int numWheels, numDoors;
		

	public:
		friend ostream& operator<<(ostream &out, const Car &c);
		
		Car(int w, int d);
		Car(int w);
		Car();

		void printVehicle(void);

		Car(Car&);		// copy by reference	
		Car(Car*);		// copy by pointer

		void setWheels(int w) { numWheels = w; }
		int getWheels(void) const { return numWheels; }

		void setDoors(int d) { numDoors = d; }
		int getDoors() const { return numDoors; }
			
		Car operator=(const Car& a) {
			setWheels(a.numWheels);
			setDoors(a.numDoors);
			return Car(getWheels(),getDoors());
		}
		Car operator==(const Car& a) {

			if ((getWheels() == a.numWheels) && (getDoors() == a.numDoors)) {			
				return true;
			}
			return false;
		}
		Car operator!=(const Car& a) {
		
			if (getWheels() == a.numWheels || getDoors() != a.numDoors) {
				return true;
			}
			return false;
		}
		Car operator++(int) {

			return Car(numWheels++, numDoors++);
		}
		Car operator++() {

			return Car(++numWheels, ++numDoors);
		}
		Car operator--(int) {

			return Car(numWheels--, numDoors--);
		}
		Car operator--() {
	
			return Car(--numWheels, --numDoors);
		}

		~Car();
	}; //class end
} //CST8219 end



