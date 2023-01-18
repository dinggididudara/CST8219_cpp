// Soomin Lee 040899389 CST8219 303
#include<iostream>

using namespace std;

namespace CST8219{
	class Car {
	private:
		int numWheels, numDoors;

	public:
		Car() { numWheels = numDoors = 0; } //constructor initialize
		Car(int w, int d){			//constrcutor for the number of wheels and doors
			numWheels = w;
			numDoors = d;
		}
		Car(int w) : Car(w,4) { }	//constructor with parameter doors = 4
		Car() : Car(4) {} //empty constructor, calling another constructor
	};
}


int main(int argc, char **argv)
{
   cout << "Hello World!" << endl;
   return 0;
}