# include "Car.h"

template <class T>
class GasolineCar : Car<T> {

public:
	inline GasolineCar() {}
	T currentGasoline = 0, maximumGasoline = 0;
	
	inline GasolineCar(float currentGasoline, float engineEfficiency) {
		this->currentGasoline = currentGasoline;
		this->maximumGasoline = currentGasoline;
		this->engineEfficiency = engineEfficiency;
	}

	inline T calculateRange() {
		return (currentGasoline * 100 / engineEfficiency);
	}
	
	inline T percentageEnergyRemaining() {
		return (currentGasoline / maximumGasoline * 100.0f);
	}
	
	inline void drive(T km) {
		currentGasoline -= (km / 100) * engineEfficiency;
		if (currentGasoline <= 0) {
			cout << "Your car is out of energy" << endl;
		}
	}

	~GasolineCar() {
		cout << "In the destructor for GasolineCar" << endl;
	}
};