// Soomin Lee 040899389 CST8219 303
# include "Car.h"

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

void CreateCar(CST8219::Car &v, int w=4, int d=2) {
	v.setWheels(w);
	v.setDoors(d);
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

			//week4--------------------------------------------------
			CST8219::Car original;

			CST8219::Car copy(original);		//pass by reference
			CST8219::Car secondCopy(&original);  //pass by pointer

			copy.printVehicle();

			CreateCar(copy, 2);
			copy.printVehicle();

			CreateCar(copy, 2, 3);
			copy.printVehicle();

			copy = secondCopy;
			copy.printVehicle();
			//week4--------------------------------------------------

			c = userInput("do you want to continue? (q/Q for quit, y/Y for continue)");
		}
   } while (c > 0);
   delete pVehicle;
     
   return 0;
}
