# include "Car.h"

template <class T>
class ElectricCar : Car<T>{
public:

	T currentCharge = 0, maximumCharge=0;
	inline ElectricCar() {}
	inline ElectricCar(T currentCharge, T engineEfficiency) {
		this->currentCharge = currentCharge;
		this->maximumCharge = currentCharge;
		this->engineEfficiency = engineEfficiency;
	}

	inline T calculateRange() {
		return (currentCharge * 100 / engineEfficiency);
	}

	inline T percentageEnergyRemaining() {
		return (currentCharge * 1.0 / maximumCharge * 1.0 * 100.0f);
	}

	inline void drive(float km) {
		currentCharge -= (km / 100) * engineEfficiency;
		if (currentCharge <= 0) {
			cout << "Your car is out of energy" << endl;
		}
	}

	~ElectricCar() {
		cout << "In the destructor for ElectricCar" << endl;
	}
};