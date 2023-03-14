// Soomin Lee 040899389 CST8219 303
#pragma once
#include <iostream>
#include <ostream>

using namespace std;
namespace Helper {
	template <typename T>
	T min(T a, T b) {
		if (a < b) {
			return a;
		}
		else if (a > b) {
			return b;
		}
		else {
			cout << "same" << endl;
		}
	}
	template <typename T>
	T max(T a, T b) {
		if (a < b) {
			return b;
		}
		else if (a > b) {
			return a;
		}
		else {
			cout << "same" << endl;
		}
	}
}
template <class T>
class Car {
	
public:
	T engineEfficiency=0;
	
	~Car() {
		//cout << "In destructor" << endl;
	} //destructor
}; //class end

	

	

	




