// Soomin Lee 040899389 CST8219 303
// Week1.cpp : Defines the entry point for the application.

#include "Week1.h"

#define usingNamespaces 1

#if usingNamespaces == 0
using namespace std;
int main()
{
	#pragma message("Using namespaces")
	cout << "Hello world!" << endl;
	return 0;
}

#elif usingNamespaces != 0
int main()
{
	#pragma message("Not using namespaces")
	std::cout << "Hello world!" << std::endl;
	return 0;
}
#endif
