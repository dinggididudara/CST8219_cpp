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
		eles if (a > b) {
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
		eles if (a > b) {
			return a;
		}
		else {
			cout << "same" << endl;
		}
	}
}

	class Car {
	
	public:
		float engineEfficiency=0;
		void testTemplateLibrary();
		~Car();
	}; //class end

	

	

	




