#define ENABLE_TESTS

#ifdef ENABLE_TESTS

#include "Tests.h"

#endif

int main()
{
#ifdef ENABLE_TESTS
	RunTests();
#endif

	return 0;
}