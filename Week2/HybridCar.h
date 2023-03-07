# include "Car.h"
# include "GasolineCar.h"
# include "ElectricCar.h"

class HybridCar : virtual public GasolineCar, virtual public ElectricCar {
protected:
	HybridCar() {}
public:
	HybridCar(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float eletricEfficiency);
	float calculateRange();

	float percentageEnergyRemaining();

	void drive(float km);


	virtual ~HybridCar() {
		cout << "In the destructor for HybridCar" << endl;
	}
};