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
		~Car(){
			cout << "In destructor" << endl;
		} //destructor
	}; //class end
} //CST8219 end


int main(int argc, char **argv)
{
   CST8219::Car veh1;
   CST8219::Car veh2(4);
   CST8219::Car veh3(4, 2);
   
   cout << "Vehicle takes " << sizeof(veh1) << endl;
   cout << "Vehicle takes " << sizeof(veh2) << endl;
   cout << "Vehicle takes " << sizeof(veh3) << endl;

   CST8219::Car* pVehicle;
   int d, w = 0;
   char c;
   do {
	   cout << "do you want to continue? (q/Q for quit)" << endl;
	   cin >> c;
	   pVehicle = 0;
		if (c == 'q' || c == 'Q') {
			delete pVehicle;
		   return 0;
		}
		else {
			do {
				
				cin.clear();
				cin.ignore(256, '\n');
				cout << "enter number of doors" << endl;
				cin >> d;
				cout << "enter number of wheels" << endl;
				cin >> w;
			} while (d < 0 || w < 0);
			pVehicle = new CST8219::Car(w, d);
		}
   } while (c != 'q' || c != 'Q');
   
   return 0;
}