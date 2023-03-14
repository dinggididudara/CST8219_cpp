# include "Car.h"
# include "GasolineCar.h"
# include "ElectricCar.h"

template <class T>
class HybridCar : GasolineCar<T>, ElectricCar<T> {

public:
	inline HybridCar() {}
	inline HybridCar(T maximumGasoline, T gasolineEfficiency, T maximumCharge, T eletricEfficiency): GasolineCar<T>(maximumGasoline, gasolineEfficiency), ElectricCar<T>(maximumCharge, eletricEfficiency) {
		
	}
	inline T calculateRange() {
		return (GasolineCar::calculateRange() + ElectricCar::calculateRange());
	}

	inline T percentageEnergyRemaining() {
		return ((GasolineCar::percentageEnergyRemaining() + ElectricCar::percentageEnergyRemaining()) / 2);
	}

	inline void drive(float km) {
		cout << km << endl;
		if (ElectricCar::calculateRange() < km) { //if use all electric energy
			float e = ElectricCar::calculateRange();
			ElectricCar::drive(e);
			float left = km - e;

			if (GasolineCar::calculateRange() < left) { //if use all gasoline energy
				GasolineCar::drive(GasolineCar::calculateRange());
				cout << "Your car is out of energy" << endl;
			}
			else { //did not use all gasoline energy
				GasolineCar::drive(left);
			}
		}
		else { //if did not use all electric
			ElectricCar::drive(km);
		}
	}


	~HybridCar() {
		cout << "In the destructor for HybridCar" << endl;
	}
};