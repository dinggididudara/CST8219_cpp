# include "ElectricCar.h"


	ElectricCar::ElectricCar(float currentCharge, float engineEfficiency) {
		this->currentCharge = currentCharge;
		this->maximumCharge = currentCharge;
		this->engineEfficiency = engineEfficiency;
	}

	float ElectricCar::calculateRange() {
		return (currentCharge * 100 / engineEfficiency);
	}

	float ElectricCar::percentageEnergyRemaining() {
		return (currentCharge / maximumCharge * 100.0f);
	}

	void ElectricCar::drive(float km) {
		currentCharge -= (km / 100) * engineEfficiency;
		if (currentCharge <= 0) {
			cout << "Your car is out of energy" << endl;
		}
	}
	
