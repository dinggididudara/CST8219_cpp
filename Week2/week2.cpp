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



int userInput(char* what) {
	char in = 0;
	while (1) {
		
		cout << what << endl;
		cin >> in; 
		
		cin.clear();
		if (isdigit(in)) {
			return (int) in;
		}
		else if (in == 'q' || in == 'Q') {  //if q or Q
			return -1;
		}
		else if (in == 'y' || in == 'Y') {
			return 1;
		}
		else {
			cout << "Wrong input. Try again." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
   CST8219::Car veh1;
   CST8219::Car veh2(4);
   CST8219::Car veh3(4, 2);
   
   cout << "Vehicle takes " << sizeof(veh1) << endl;
   cout << "Vehicle takes " << sizeof(veh2) << endl;
   cout << "Vehicle takes " << sizeof(veh3) << endl;

   CST8219::Car* pVehicle;
   int d, w;
   int c=0;
   do {
	    pVehicle = 0;
	    	  
		if (c == -1) {  //if quit
		   cout << "Bye" << endl;
		   break;
		}
		else {
			d = userInput("enter number of doors");
			w = userInput("enter number of wheels");
			
			pVehicle = new CST8219::Car(w, d);
			c = userInput("do you want to continue? (q/Q for quit, y/Y for continue)");
		}
   } while (c > 0);
   delete pVehicle;
   return 0;
}
