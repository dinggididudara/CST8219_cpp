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
   CST8219::Car original;
   CST8219::Car copy(original);		//pass by reference
			
   cout << "Original is: " << original << ". copy is: " << copy << endl;

   cout << "Increment original: " << original++ << endl;
   cout << "Increment copy:" << ++copy << endl;

   cout << "Decrement original:" << --original << endl;
   cout << "Decrement copy:" << copy-- << endl;

   // should be true :
   cout << "Compare equality 1: " << (original == copy) << endl;

   //should be false:
   cout << "Compare equality 2: " << (--original == ++copy) << endl;

   //should be true:
   cout << "Compare inequality: " << (original != copy) << endl;

   //This should make original = copy, and then return a Car for output:
   cout << "Assignment operator: " << (original = copy) << endl;


   return 0;
}
