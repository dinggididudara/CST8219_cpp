# include "HybridCar.h"

	HybridCar::HybridCar(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float eletricEfficiency) : GasolineCar(maximumGasoline, gasolineEfficiency),	ElectricCar(maximumCharge, eletricEfficiency){
		/*GasolineCar(maximumGasoline, gasolineEfficiency);
		ElectricCar(maximumCharge, eletricEfficiency);*/
	}
	float HybridCar::calculateRange() {
		return (GasolineCar::calculateRange() + ElectricCar::calculateRange());
	}

	float HybridCar::percentageEnergyRemaining() {
		return ((GasolineCar::percentageEnergyRemaining() + ElectricCar::percentageEnergyRemaining()) / 2);
	}

	void HybridCar::drive(float km) {
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

