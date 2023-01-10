// Week1.cpp : Defines the entry point for the application.
//

#include "Week1.h"

#define usingNamespaces 0

#if using namespace std
#pragma message("Using namespaces")
int main()
{
	cout << "Hello world!" << endl;
	return 0;
}

#elif ??
#pragma message("Not using namespaces")
int main()
{
	std::count << "Hellow world!" << std::endl;
	return 0;
}
#endif

