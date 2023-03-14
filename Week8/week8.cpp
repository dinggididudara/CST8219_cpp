// Soomin Lee 040899389 CST8219 303

# include "HybridCar.h"
# include <vector>

void testTemplateLibrary() {
	vector<int> randomNumber;
	for (int i = 0; i < 10; i++) {
		randomNumber.push_back(rand());
	}

	for (vector<int>::iterator it = randomNumber.begin(); it != randomNumber.end(); it++) {
		cout << *it << endl;
	}
}

template<class T>
T testCar(T pCar, const char* CarName) {
	cout << CarName << "'s range is : " << pCar->calculateRange() << endl;
	pCar->drive(120);
	cout << CarName << "'s energy left is : " << pCar->percentageEnergyRemaining() << endl;
	cout << CarName << "'s range is now : " << pCar->calculateRange() << endl;

	return pCar;
}
int main(int argc, char **argv)
{   
	delete testCar(new GasolineCar<float>(50, 7.1), "Corolla"); 
	// 50L of gas, 7.1L/100km
	delete testCar(new HybridCar<double>(42, 4.3, 8.8, 22.0), "Prius"); 
	// 42L of gas, 4.3L/100km, 8.8kWh, 22kWh/100km
	delete testCar(new ElectricCar<int>(75, 16), "Tesla 3");
	// 75kWh, 16kWh/100km

	cout << "min of 5 and 7 is:" << Helper::min(5, 7) << endl;
	cout << "min of 5 and 7 is:" << Helper::max(5, 7) << endl;

	cout << "min of A and B is:" << Helper::min('A', 'B') << endl;
	cout << "max of A and B is:" << Helper::max('A', 'B') << endl;

	cout << "min of string(Hello) and string(World) is: " << Helper::min(string("Hello"), string("World")) << endl;
	cout << "max of string(Hello) and string(World) is: " << Helper::max(string("Hello"), string("World")) << endl;
	testTemplateLibrary();
   return 0;
}
