// Week1.cpp : Defines the entry point for the application.
//

#include "Week1.h"

#define usingNamespaces 0

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
	std::count << "Hellow world!" << std::endl;
	return 0;
}
#endif
