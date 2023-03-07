# include "Car.h"

class GasolineCar : virtual public Car {
protected:
	GasolineCar() {}
public:
	float currentGasoline = 0, maximumGasoline = 0;
	
	GasolineCar(float currentGasoline, float engineEfficiency);	

	float calculateRange();
	
	float percentageEnergyRemaining();
	
	void drive(float km);

	virtual ~GasolineCar() {
		cout << "In the destructor for GasolineCar" << endl;
	}
};