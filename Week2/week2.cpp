// Soomin Lee 040899389 CST8219 303
#include<iostream>

using namespace std;

namespace CST8219{
	class Car {
	private:
		int numWheels, numDoors;

	public:
		Car(int w, int d){			//constrcutor for the number of wheels and doors
			numWheels = w;
			numDoors = d;

			cout << "In constructor with 2 parameters" << endl;
		}
		Car(int w) : Car(w, 4) { 	//constructor with parameter doors = 4
			cout << "In constructor with 1 parameters, wheels= " << w << endl;
		}
		Car() : Car(4) {	//empty constructor, calling another constructor
			cout << "In constructor with 0 parameters" << endl;
		} 
		~Car(){} //destructor
	}; //class end
} //CST8219 end


int main(int argc, char **argv)
{
	CST8219::Car myVehicle(4);
   cout << "I made a Car!" << endl;
   return 0;
}