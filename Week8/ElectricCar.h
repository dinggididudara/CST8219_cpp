# include "Car.h"

class ElectricCar : public Car {
protected:
	ElectricCar() {}
public:
	float currentCharge = 0, maximumCharge=0;
	
	ElectricCar(float currentCharge, float engineEfficiency);

	float calculateRange();

	float percentageEnergyRemaining();

	void drive(float km);	

	~ElectricCar() {
		cout << "In the destructor for ElectricCar" << endl;
	}
};