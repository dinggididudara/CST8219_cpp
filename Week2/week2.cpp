// Soomin Lee 040899389 CST8219 303

# include "HybridCar.h"

//int userInput(char* what) {
//	char in = 0;
//	while (1) {
//		
//		cout << what << endl;
//		cin >> in; 
//		
//		cin.clear();
//		if (isdigit(in)) {
//			return (int) in;
//		}
//		else if (in == 'q' || in == 'Q') {  //if q or Q
//			return -1;
//		}
//		else if (in == 'y' || in == 'Y') {
//			return 1;
//		}
//		else {
//			cout << "Wrong input. Try again." << endl;
//			cin.clear();
//			cin.ignore(256, '\n');
//		}
//	}
//	return -1;
//}
//
//void CreateCar(CST8219::Car &v, int w=4, int d=2) {
//	v.setWheels(w);
//	v.setDoors(d);
//}
Car* testCar(Car* pCar, const char* CarName) {
	cout << CarName << "'s range is : " << pCar->calculateRange() << endl;
	pCar->drive(120);
	cout << CarName << "'s energy left is : " << pCar->percentageEnergyRemaining() << endl;
	cout << CarName << "'s range is now : " << pCar->calculateRange() << endl;

	return pCar;
}
int main(int argc, char **argv)
{
   //CST8219::Car original;
   //CST8219::Car copy(original);		//pass by reference
			//
   //cout << "Original is: " << original << ". copy is: " << copy << endl;

   //cout << "Increment original: " << original++ << endl;
   //cout << "Increment copy:" << ++copy << endl;

   //cout << "Decrement original:" << --original << endl;
   //cout << "Decrement copy:" << copy-- << endl;

   //// should be true :
   //cout << "Compare equality 1: " << (original == copy) << endl;

   ////should be false:
   //cout << "Compare equality 2: " << (--original == ++copy) << endl;

   ////should be true:
   //cout << "Compare inequality: " << (original != copy) << endl;

   ////This should make original = copy, and then return a Car for output:
   //cout << "Assignment operator: " << (original = copy) << endl;

	delete testCar(new GasolineCar(50, 6.3), "Corolla"); 
	// 50L of gas, 6.3L/100km
	delete testCar(dynamic_cast<ElectricCar*>(new HybridCar(42, 4.1, 9.8, 22.0)), "Prius"); 
	// 42L of gas, 4.1L/100km, 9.8kWh, 22kWh/100km
	delete testCar(new ElectricCar(78, 16), "Tesla 3");
	// 78kWh, 16kWh/100km

   return 0;
}
