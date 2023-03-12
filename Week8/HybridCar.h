# include "Car.h"
# include "GasolineCar.h"
# include "ElectricCar.h"

class HybridCar : public GasolineCar, public ElectricCar {
protected:
	HybridCar() {}
public:
	HybridCar(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float eletricEfficiency);
	float calculateRange();

	float percentageEnergyRemaining();

	void drive(float km);


	~HybridCar() {
		cout << "In the destructor for HybridCar" << endl;
	}
};