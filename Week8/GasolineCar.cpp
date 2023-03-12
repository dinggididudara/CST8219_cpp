# include "GasolineCar.h"

	GasolineCar::GasolineCar(float currentGasoline, float engineEfficiency) {
		this->currentGasoline = currentGasoline;
		this->maximumGasoline = currentGasoline;
		this->engineEfficiency = engineEfficiency;
	}

	float GasolineCar::calculateRange() {
		return (currentGasoline * 100 / engineEfficiency);
	}

	float GasolineCar::percentageEnergyRemaining() {
		return (currentGasoline / maximumGasoline * 100.0f);
	}

	void GasolineCar::drive(float km) {
		currentGasoline -= (km / 100) * engineEfficiency;
		if (currentGasoline <= 0) {
			cout << "Your car is out of energy" << endl;
		}
	}

