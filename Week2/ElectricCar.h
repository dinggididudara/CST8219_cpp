# include "Car.h"

class ElectricCar : virtual public Car {
protected:
	ElectricCar() {}
public:
	float currentCharge = 0, maximumCharge=0;
	
	ElectricCar(float currentCharge, float engineEfficiency);

	float calculateRange();

	float percentageEnergyRemaining();

	void drive(float km);	

	virtual ~ElectricCar() {
		cout << "In the destructor for ElectricCar" << endl;
	}
};